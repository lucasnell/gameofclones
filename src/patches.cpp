
#include <RcppArmadillo.h>      // arma namespace
#include <vector>               // vector class
#include <functional>           // std::greater
#include <random>               // normal distribution
#include <pcg/pcg_random.hpp>   // pcg prng
#include "clonewars_types.hpp"  // integer types
#include "patches.hpp"          // patch classes
#include "pcg.hpp"              // runif_ fxns



using namespace Rcpp;









/*
 Adjust for potential extinction or re-colonization:
 */
void OnePatch::extinct_colonize(const uint32& i) {

    AphidPop& ap(aphids[i]);

    double N = ap.total_aphids();

    if (N < extinct_N) {
        ap.clear();
    } else {
        empty = false;
        ap.extinct = false;
    }

    return;
}


/*
 Carrying capacity for patch.
 It depends on the Leslie matrix for each line's apterous aphids.
 I'm assuming apterous ones drive the carrying capacity, rather than alates, because
 they should be much more numerous.
 */

double OnePatch::carrying_capacity() const {

    arma::vec cc(aphids.size());
    arma::vec Ns(aphids.size());
    double total_N = 0;

    arma::mat L;
    arma::cx_vec eigval;
    double ev;

    for (uint32 i = 0; i < aphids.size(); i++) {

        Ns[i] = aphids[i].total_aphids();

        total_N += Ns[i];

        /*
         The line `aphids[i].apterous.alate_prop(z / CC),` means that the calculation
         of the carrying capacity depends on its own value.
         Unless I can come up with a different way of parameterizing this
         that fixes this circularity, I'm only going to consider apterous aphids
         for determining the carrying capacity.
         */
        // combine_leslies(L,
        //                 aphids[i].apterous.leslie(),
        //                 aphids[i].alates.leslie(),
        //                 aphids[i].apterous.alate_prop(z / CC),
        //                 aphids[i].alates.disp_rate(),
        //                 aphids[i].alates.disp_mort(),
        //                 aphids[i].alates.disp_start());
        L = aphids[i].apterous.leslie();

        eigval = arma::eig_gen( L );
        ev = eigval(0).real();
        cc[i] = (ev - 1) * K;
    }

    double avg_cc;

    if (total_N > 0) {
        avg_cc = arma::accu(cc % Ns / total_N);
    } else avg_cc = arma::mean(cc);

    return avg_cc;
}





void OnePatch::update_z_CC_wilted() {


    z = total_aphids();
    CC = carrying_capacity();

    // Once it turns wilted, it stays that way until cleared
    if (wilted_) return;
    wilted_ = z >= (CC * death_prop);

    return;
}



/*
 Iterate one time step, after calculating dispersal numbers
 */
void OnePatch::update_pops(const arma::cube& emigrants,
                           const arma::cube& immigrants,
                           pcg32& eng) {

    update_z_CC_wilted();

    S = 1 / (1 + z / K);

    empty = true;

    for (uint32 i = 0; i < aphids.size(); i++) {

        // Update population, including process error and dispersal:
        aphids[i].update_pop(this,
                             emigrants.slice(i).col(this_j),
                             immigrants.slice(i).col(this_j),
                             z / CC,
                             eng);

        if (wilted_) {
            aphids[i].apterous.X *= death_mort;
            aphids[i].alates.X *= death_mort;
        }

        // Adjust for potential extinction or re-colonization:
        extinct_colonize(i);

    }

    age++;

    return;

}
// Same but minus stochasticity
void OnePatch::update_pops(const arma::cube& emigrants,
                           const arma::cube& immigrants) {

    update_z_CC_wilted();

    S = 1 / (1 + z / K);

    empty = true;

    for (uint32 i = 0; i < aphids.size(); i++) {

        aphids[i].update_pop(this,
                             emigrants.slice(i).col(this_j),
                             immigrants.slice(i).col(this_j),
                             z / CC);

        if (wilted_) {
            aphids[i].apterous.X *= death_mort;
            aphids[i].alates.X *= death_mort;
        }

        extinct_colonize(i);

    }

    age++;

    return;

}





// Do the actual clearing of patches while avoiding extinction
template <typename T>
inline void AllPatches::do_clearing(std::vector<PatchClearingInfo<T>>& clear_patches,
                                    double& remaining,
                                    std::vector<bool>& wilted,
                                    pcg32& eng) {

    int n_patches = patches.size();
    int n_wilted = std::accumulate(wilted.begin(), wilted.end(), 0);

    if (clear_patches.size() == 0 && n_wilted < n_patches) return;

    /*
     This is to avoid removing no plants when they're all dying.
     Clearing the least-populated plant here means that there's a healthy plant
     for aphids to disperse to, which hopefully reduces the chance of extinction
     before the next time plants get checked.
     */
    if (clear_patches.size() == 0 && n_wilted == n_patches) {
        for (const OnePatch& p : patches) {
            double N = p.total_aphids();
            clear_patches.push_back(PatchClearingInfo<T>(p.this_j, N, true,
                                                         static_cast<T>(N)));
        }
        // Sort ascending by `N`:
        std::sort(clear_patches.begin(), clear_patches.end());

        remaining = 0;

        for (uint32 i = 1; i < n_patches; i++) {
            remaining += clear_patches.back().N;
            clear_patches.pop_back();
        }


        double K = get_K(eng);
        double death_mort = get_death_mort(eng);

        patches[clear_patches.front().ind].clear(K, death_mort);

        return;

    }

    /*
     If removing all these patches cause total extinction, we need to remove
     some indices from `inds`.
     We'll sort (high to low) the vector by the threshold variable (age or # aphids),
     then remove the last item in the vector until we have aphids again.
     */
    if (remaining == 0) {

        // Sort descending:
        std::sort(clear_patches.begin(), clear_patches.end(),
                  std::greater<PatchClearingInfo<T>>());

        while (remaining == 0) {
            remaining += clear_patches.back().N;
            clear_patches.pop_back();
        }

    }

    double K;
    double death_mort;

    for (uint32 i = 0; i < clear_patches.size(); i++) {

        K = get_K(eng);
        death_mort = get_death_mort(eng);

        patches[clear_patches[i].ind].clear(K, death_mort);
    }


    return;
}




// Clear patches by either a maximum age or total abundance
void AllPatches::clear_patches(const uint32& max_age,
                               pcg32& eng) {

    std::vector<PatchClearingInfo<uint32>> clear_patches;
    clear_patches.reserve(patches.size());

    // # remaining aphids for non-cleared patches
    double remaining = 0;

    // keeping track of dying plants:
    std::vector<bool> wilted;
    wilted.reserve(patches.size());

    for (const OnePatch& p : patches) {
        double N = p.total_aphids();
        wilted.push_back(p.wilted());
        if (p.age > max_age || wilted.back()) {
            clear_patches.push_back(PatchClearingInfo<uint32>(p.this_j, N, wilted.back(),
                                                              p.age));
        } else remaining += N;
    }

    do_clearing<uint32>(clear_patches, remaining, wilted, eng);

    return;
}


void AllPatches::clear_patches(const double& max_N,
                               pcg32& eng) {

    std::vector<PatchClearingInfo<double>> clear_patches;
    clear_patches.reserve(patches.size());

    double remaining = 0;

    std::vector<bool> wilted;
    wilted.reserve(patches.size());

    for (const OnePatch& p : patches) {
        double N = p.total_aphids();
        wilted.push_back(p.wilted());
        if (N > max_N || wilted.back()) {
            clear_patches.push_back(PatchClearingInfo<double>(p.this_j, N, wilted.back(),
                                                              N));
        } else remaining += N;
    }

    do_clearing<double>(clear_patches, remaining, wilted, eng);

    return;
}
