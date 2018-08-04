// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "cwsims_types.hpp"
#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// sim_cages_
std::vector<arma::cube> sim_cages_(const uint32& n_cages, const arma::mat& N_0, const uint32& max_t, const arma::rowvec& R, const arma::rowvec& A, const arma::mat& D_mat, const double& process_error, const arma::rowvec& plant_mort_0, const arma::rowvec& plant_mort_1, const double& plant_death_age_mean, const double& plant_death_age_sd, const std::vector<uint32>& repl_times, const sint32& repl_age, const double& extinct_N, const uint32& n_cores, const bool& by_cage, const bool& show_progress);
RcppExport SEXP _cwsims_sim_cages_(SEXP n_cagesSEXP, SEXP N_0SEXP, SEXP max_tSEXP, SEXP RSEXP, SEXP ASEXP, SEXP D_matSEXP, SEXP process_errorSEXP, SEXP plant_mort_0SEXP, SEXP plant_mort_1SEXP, SEXP plant_death_age_meanSEXP, SEXP plant_death_age_sdSEXP, SEXP repl_timesSEXP, SEXP repl_ageSEXP, SEXP extinct_NSEXP, SEXP n_coresSEXP, SEXP by_cageSEXP, SEXP show_progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32& >::type n_cages(n_cagesSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type N_0(N_0SEXP);
    Rcpp::traits::input_parameter< const uint32& >::type max_t(max_tSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type R(RSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type D_mat(D_matSEXP);
    Rcpp::traits::input_parameter< const double& >::type process_error(process_errorSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type plant_mort_0(plant_mort_0SEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type plant_mort_1(plant_mort_1SEXP);
    Rcpp::traits::input_parameter< const double& >::type plant_death_age_mean(plant_death_age_meanSEXP);
    Rcpp::traits::input_parameter< const double& >::type plant_death_age_sd(plant_death_age_sdSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type repl_times(repl_timesSEXP);
    Rcpp::traits::input_parameter< const sint32& >::type repl_age(repl_ageSEXP);
    Rcpp::traits::input_parameter< const double& >::type extinct_N(extinct_NSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    Rcpp::traits::input_parameter< const bool& >::type by_cage(by_cageSEXP);
    Rcpp::traits::input_parameter< const bool& >::type show_progress(show_progressSEXP);
    rcpp_result_gen = Rcpp::wrap(sim_cages_(n_cages, N_0, max_t, R, A, D_mat, process_error, plant_mort_0, plant_mort_1, plant_death_age_mean, plant_death_age_sd, repl_times, repl_age, extinct_N, n_cores, by_cage, show_progress));
    return rcpp_result_gen;
END_RCPP
}
// grouped_mean
arma::mat grouped_mean(SEXP pBigMat, const bool& by_plant, const bool& by_date, const bool& zeros, const bool& show_progress);
RcppExport SEXP _cwsims_grouped_mean(SEXP pBigMatSEXP, SEXP by_plantSEXP, SEXP by_dateSEXP, SEXP zerosSEXP, SEXP show_progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type pBigMat(pBigMatSEXP);
    Rcpp::traits::input_parameter< const bool& >::type by_plant(by_plantSEXP);
    Rcpp::traits::input_parameter< const bool& >::type by_date(by_dateSEXP);
    Rcpp::traits::input_parameter< const bool& >::type zeros(zerosSEXP);
    Rcpp::traits::input_parameter< const bool& >::type show_progress(show_progressSEXP);
    rcpp_result_gen = Rcpp::wrap(grouped_mean(pBigMat, by_plant, by_date, zeros, show_progress));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_cwsims_sim_cages_", (DL_FUNC) &_cwsims_sim_cages_, 17},
    {"_cwsims_grouped_mean", (DL_FUNC) &_cwsims_grouped_mean, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_cwsims(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
