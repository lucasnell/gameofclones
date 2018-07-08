/*
    clonewars is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    clonewars is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with clonewars.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.17.0

#include <stan/model/model_header.hpp>

namespace model_one_line_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_one_line");
    reader.add_event(110, 110, "end", "model_one_line");
    return reader;
}

#include <meta_header.hpp>
 class model_one_line : public prob_grad {
private:
    int N_ts;
    vector<int> reps_ts;
    int max_reps;
    matrix_d X;
public:
    model_one_line(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_one_line(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_one_line_namespace::model_one_line";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 44;
            context__.validate_dims("data initialization", "N_ts", "int", context__.to_vec());
            N_ts = int(0);
            vals_i__ = context__.vals_i("N_ts");
            pos__ = 0;
            N_ts = vals_i__[pos__++];
            current_statement_begin__ = 45;
            validate_non_negative_index("reps_ts", "N_ts", N_ts);
            context__.validate_dims("data initialization", "reps_ts", "int", context__.to_vec(N_ts));
            validate_non_negative_index("reps_ts", "N_ts", N_ts);
            reps_ts = std::vector<int>(N_ts,int(0));
            vals_i__ = context__.vals_i("reps_ts");
            pos__ = 0;
            size_t reps_ts_limit_0__ = N_ts;
            for (size_t i_0__ = 0; i_0__ < reps_ts_limit_0__; ++i_0__) {
                reps_ts[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 46;
            context__.validate_dims("data initialization", "max_reps", "int", context__.to_vec());
            max_reps = int(0);
            vals_i__ = context__.vals_i("max_reps");
            pos__ = 0;
            max_reps = vals_i__[pos__++];
            current_statement_begin__ = 47;
            validate_non_negative_index("X", "max_reps", max_reps);
            validate_non_negative_index("X", "N_ts", N_ts);
            context__.validate_dims("data initialization", "X", "matrix_d", context__.to_vec(max_reps,N_ts));
            validate_non_negative_index("X", "max_reps", max_reps);
            validate_non_negative_index("X", "N_ts", N_ts);
            X = matrix_d(static_cast<Eigen::VectorXd::Index>(max_reps),static_cast<Eigen::VectorXd::Index>(N_ts));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_m_mat_lim__ = max_reps;
            size_t X_n_mat_lim__ = N_ts;
            for (size_t n_mat__ = 0; n_mat__ < X_n_mat_lim__; ++n_mat__) {
                for (size_t m_mat__ = 0; m_mat__ < X_m_mat_lim__; ++m_mat__) {
                    X(m_mat__,n_mat__) = vals_r__[pos__++];
                }
            }

            // validate, data variables
            current_statement_begin__ = 44;
            check_greater_or_equal(function__,"N_ts",N_ts,1);
            current_statement_begin__ = 45;
            for (int k0__ = 0; k0__ < N_ts; ++k0__) {
                check_greater_or_equal(function__,"reps_ts[k0__]",reps_ts[k0__],1);
            }
            current_statement_begin__ = 46;
            check_greater_or_equal(function__,"max_reps",max_reps,1);
            current_statement_begin__ = 47;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 52;
            ++num_params_r__;
            current_statement_begin__ = 53;
            ++num_params_r__;
            current_statement_begin__ = 54;
            ++num_params_r__;
            current_statement_begin__ = 56;
            ++num_params_r__;
            current_statement_begin__ = 57;
            ++num_params_r__;
            current_statement_begin__ = 58;
            ++num_params_r__;
            current_statement_begin__ = 60;
            ++num_params_r__;
            current_statement_begin__ = 61;
            ++num_params_r__;
            current_statement_begin__ = 62;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_one_line() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("mean_R0")))
            throw std::runtime_error("variable mean_R0 missing");
        vals_r__ = context__.vals_r("mean_R0");
        pos__ = 0U;
        context__.validate_dims("initialization", "mean_R0", "double", context__.to_vec());
        double mean_R0(0);
        mean_R0 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mean_R0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mean_R0: ") + e.what());
        }

        if (!(context__.contains_r("mean_alpha")))
            throw std::runtime_error("variable mean_alpha missing");
        vals_r__ = context__.vals_r("mean_alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "mean_alpha", "double", context__.to_vec());
        double mean_alpha(0);
        mean_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mean_alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mean_alpha: ") + e.what());
        }

        if (!(context__.contains_r("mean_process")))
            throw std::runtime_error("variable mean_process missing");
        vals_r__ = context__.vals_r("mean_process");
        pos__ = 0U;
        context__.validate_dims("initialization", "mean_process", "double", context__.to_vec());
        double mean_process(0);
        mean_process = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mean_process);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mean_process: ") + e.what());
        }

        if (!(context__.contains_r("sigma_R0")))
            throw std::runtime_error("variable sigma_R0 missing");
        vals_r__ = context__.vals_r("sigma_R0");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_R0", "double", context__.to_vec());
        double sigma_R0(0);
        sigma_R0 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_R0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_R0: ") + e.what());
        }

        if (!(context__.contains_r("sigma_alpha")))
            throw std::runtime_error("variable sigma_alpha missing");
        vals_r__ = context__.vals_r("sigma_alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_alpha", "double", context__.to_vec());
        double sigma_alpha(0);
        sigma_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_alpha: ") + e.what());
        }

        if (!(context__.contains_r("sigma_process")))
            throw std::runtime_error("variable sigma_process missing");
        vals_r__ = context__.vals_r("sigma_process");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_process", "double", context__.to_vec());
        double sigma_process(0);
        sigma_process = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_process);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_process: ") + e.what());
        }

        if (!(context__.contains_r("Z_R0")))
            throw std::runtime_error("variable Z_R0 missing");
        vals_r__ = context__.vals_r("Z_R0");
        pos__ = 0U;
        context__.validate_dims("initialization", "Z_R0", "double", context__.to_vec());
        double Z_R0(0);
        Z_R0 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,Z_R0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable Z_R0: ") + e.what());
        }

        if (!(context__.contains_r("Z_alpha")))
            throw std::runtime_error("variable Z_alpha missing");
        vals_r__ = context__.vals_r("Z_alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "Z_alpha", "double", context__.to_vec());
        double Z_alpha(0);
        Z_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,Z_alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable Z_alpha: ") + e.what());
        }

        if (!(context__.contains_r("Z_process")))
            throw std::runtime_error("variable Z_process missing");
        vals_r__ = context__.vals_r("Z_process");
        pos__ = 0U;
        context__.validate_dims("initialization", "Z_process", "double", context__.to_vec());
        double Z_process(0);
        Z_process = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,Z_process);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable Z_process: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<T__> in__(params_r__,params_i__);

            T__ mean_R0;
            (void) mean_R0;  // dummy to suppress unused var warning
            if (jacobian__)
                mean_R0 = in__.scalar_lb_constrain(0,lp__);
            else
                mean_R0 = in__.scalar_lb_constrain(0);

            T__ mean_alpha;
            (void) mean_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                mean_alpha = in__.scalar_lb_constrain(0,lp__);
            else
                mean_alpha = in__.scalar_lb_constrain(0);

            T__ mean_process;
            (void) mean_process;  // dummy to suppress unused var warning
            if (jacobian__)
                mean_process = in__.scalar_lb_constrain(0,lp__);
            else
                mean_process = in__.scalar_lb_constrain(0);

            T__ sigma_R0;
            (void) sigma_R0;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_R0 = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_R0 = in__.scalar_lb_constrain(0);

            T__ sigma_alpha;
            (void) sigma_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_alpha = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_alpha = in__.scalar_lb_constrain(0);

            T__ sigma_process;
            (void) sigma_process;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_process = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_process = in__.scalar_lb_constrain(0);

            T__ Z_R0;
            (void) Z_R0;  // dummy to suppress unused var warning
            if (jacobian__)
                Z_R0 = in__.scalar_lb_constrain(0,lp__);
            else
                Z_R0 = in__.scalar_lb_constrain(0);

            T__ Z_alpha;
            (void) Z_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                Z_alpha = in__.scalar_lb_constrain(0,lp__);
            else
                Z_alpha = in__.scalar_lb_constrain(0);

            T__ Z_process;
            (void) Z_process;  // dummy to suppress unused var warning
            if (jacobian__)
                Z_process = in__.scalar_lb_constrain(0,lp__);
            else
                Z_process = in__.scalar_lb_constrain(0);


            // transformed parameters
            current_statement_begin__ = 66;
            T__ R0;
            (void) R0;  // dummy to suppress unused var warning

            stan::math::initialize(R0, DUMMY_VAR__);
            stan::math::fill(R0,DUMMY_VAR__);
            current_statement_begin__ = 67;
            T__ alpha;
            (void) alpha;  // dummy to suppress unused var warning

            stan::math::initialize(alpha, DUMMY_VAR__);
            stan::math::fill(alpha,DUMMY_VAR__);
            current_statement_begin__ = 68;
            T__ process;
            (void) process;  // dummy to suppress unused var warning

            stan::math::initialize(process, DUMMY_VAR__);
            stan::math::fill(process,DUMMY_VAR__);
            current_statement_begin__ = 69;
            validate_non_negative_index("X_pred", "max_reps", max_reps);
            validate_non_negative_index("X_pred", "N_ts", N_ts);
            Eigen::Matrix<T__,Eigen::Dynamic,Eigen::Dynamic>  X_pred(static_cast<Eigen::VectorXd::Index>(max_reps),static_cast<Eigen::VectorXd::Index>(N_ts));
            (void) X_pred;  // dummy to suppress unused var warning

            stan::math::initialize(X_pred, DUMMY_VAR__);
            stan::math::fill(X_pred,DUMMY_VAR__);


            current_statement_begin__ = 71;
            stan::math::assign(R0, (mean_R0 + (sigma_R0 * Z_R0)));
            current_statement_begin__ = 72;
            stan::math::assign(alpha, (mean_alpha + (sigma_alpha * Z_alpha)));
            current_statement_begin__ = 73;
            stan::math::assign(process, (mean_process + (sigma_process * Z_process)));
            current_statement_begin__ = 75;
            for (int i = 1; i <= N_ts; ++i) {

                current_statement_begin__ = 76;
                stan::math::assign(get_base1_lhs(X_pred,1,i,"X_pred",1), get_base1(X,1,i,"X",1));
                current_statement_begin__ = 77;
                stan::model::assign(X_pred, 
                            stan::model::cons_list(stan::model::index_min_max(2, get_base1(reps_ts,i,"reps_ts",1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), 
                            add(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (get_base1(reps_ts,i,"reps_ts",1) - 1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), "X"),multiply(R0,subtract(1,multiply(alpha,exp(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (get_base1(reps_ts,i,"reps_ts",1) - 1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), "X")))))), 
                            "assigning variable X_pred");
                current_statement_begin__ = 79;
                if (as_bool(logical_lt(get_base1(reps_ts,i,"reps_ts",1),max_reps))) {

                    current_statement_begin__ = 80;
                    for (int j = (get_base1(reps_ts,i,"reps_ts",1) + 1); j <= max_reps; ++j) {
                        current_statement_begin__ = 80;
                        stan::math::assign(get_base1_lhs(X_pred,j,i,"X_pred",1), 0);
                    }
                }
            }

            // validate transformed parameters
            if (stan::math::is_uninitialized(R0)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: R0";
                throw std::runtime_error(msg__.str());
            }
            if (stan::math::is_uninitialized(alpha)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: alpha";
                throw std::runtime_error(msg__.str());
            }
            if (stan::math::is_uninitialized(process)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: process";
                throw std::runtime_error(msg__.str());
            }
            for (int i0__ = 0; i0__ < max_reps; ++i0__) {
                for (int i1__ = 0; i1__ < N_ts; ++i1__) {
                    if (stan::math::is_uninitialized(X_pred(i0__,i1__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: X_pred" << '[' << i0__ << ']' << '[' << i1__ << ']';
                        throw std::runtime_error(msg__.str());
                    }
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 66;
            check_greater_or_equal(function__,"R0",R0,0);
            current_statement_begin__ = 67;
            check_greater_or_equal(function__,"alpha",alpha,0);
            current_statement_begin__ = 68;
            check_greater_or_equal(function__,"process",process,0);
            current_statement_begin__ = 69;

            // model body

            current_statement_begin__ = 90;
            lp_accum__.add(normal_log<propto__>(mean_R0, 0.28999999999999998, (0.022599999999999999 * 10)));
            current_statement_begin__ = 91;
            lp_accum__.add(normal_log<propto__>(mean_alpha, 0.0028999999999999998, (0.00036400000000000001 * 10)));
            current_statement_begin__ = 92;
            lp_accum__.add(normal_log<propto__>(mean_process, 0.0028999999999999998, (0.00036400000000000001 * 10)));
            current_statement_begin__ = 94;
            lp_accum__.add(normal_log<propto__>(sigma_R0, 0, 1));
            current_statement_begin__ = 95;
            lp_accum__.add(normal_log<propto__>(sigma_alpha, 0, (0.00036400000000000001 * 10)));
            current_statement_begin__ = 96;
            lp_accum__.add(normal_log<propto__>(sigma_process, 0, (0.00036400000000000001 * 10)));
            current_statement_begin__ = 98;
            lp_accum__.add(normal_log<propto__>(Z_R0, 0, 1));
            current_statement_begin__ = 99;
            lp_accum__.add(normal_log<propto__>(Z_alpha, 0, 1));
            current_statement_begin__ = 100;
            lp_accum__.add(normal_log<propto__>(Z_process, 0, 1));
            current_statement_begin__ = 106;
            for (int i = 1; i <= N_ts; ++i) {

                current_statement_begin__ = 107;
                lp_accum__.add(normal_log<propto__>(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(2, get_base1(reps_ts,i,"reps_ts",1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), "X"), stan::model::rvalue(X_pred, stan::model::cons_list(stan::model::index_min_max(2, get_base1(reps_ts,i,"reps_ts",1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), "X_pred"), process));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mean_R0");
        names__.push_back("mean_alpha");
        names__.push_back("mean_process");
        names__.push_back("sigma_R0");
        names__.push_back("sigma_alpha");
        names__.push_back("sigma_process");
        names__.push_back("Z_R0");
        names__.push_back("Z_alpha");
        names__.push_back("Z_process");
        names__.push_back("R0");
        names__.push_back("alpha");
        names__.push_back("process");
        names__.push_back("X_pred");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(max_reps);
        dims__.push_back(N_ts);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "model_one_line_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double mean_R0 = in__.scalar_lb_constrain(0);
        double mean_alpha = in__.scalar_lb_constrain(0);
        double mean_process = in__.scalar_lb_constrain(0);
        double sigma_R0 = in__.scalar_lb_constrain(0);
        double sigma_alpha = in__.scalar_lb_constrain(0);
        double sigma_process = in__.scalar_lb_constrain(0);
        double Z_R0 = in__.scalar_lb_constrain(0);
        double Z_alpha = in__.scalar_lb_constrain(0);
        double Z_process = in__.scalar_lb_constrain(0);
        vars__.push_back(mean_R0);
        vars__.push_back(mean_alpha);
        vars__.push_back(mean_process);
        vars__.push_back(sigma_R0);
        vars__.push_back(sigma_alpha);
        vars__.push_back(sigma_process);
        vars__.push_back(Z_R0);
        vars__.push_back(Z_alpha);
        vars__.push_back(Z_process);

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 66;
            double R0(0.0);
            (void) R0;  // dummy to suppress unused var warning

            stan::math::initialize(R0, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(R0,DUMMY_VAR__);
            current_statement_begin__ = 67;
            double alpha(0.0);
            (void) alpha;  // dummy to suppress unused var warning

            stan::math::initialize(alpha, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(alpha,DUMMY_VAR__);
            current_statement_begin__ = 68;
            double process(0.0);
            (void) process;  // dummy to suppress unused var warning

            stan::math::initialize(process, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(process,DUMMY_VAR__);
            current_statement_begin__ = 69;
            validate_non_negative_index("X_pred", "max_reps", max_reps);
            validate_non_negative_index("X_pred", "N_ts", N_ts);
            matrix_d X_pred(static_cast<Eigen::VectorXd::Index>(max_reps),static_cast<Eigen::VectorXd::Index>(N_ts));
            (void) X_pred;  // dummy to suppress unused var warning

            stan::math::initialize(X_pred, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(X_pred,DUMMY_VAR__);


            current_statement_begin__ = 71;
            stan::math::assign(R0, (mean_R0 + (sigma_R0 * Z_R0)));
            current_statement_begin__ = 72;
            stan::math::assign(alpha, (mean_alpha + (sigma_alpha * Z_alpha)));
            current_statement_begin__ = 73;
            stan::math::assign(process, (mean_process + (sigma_process * Z_process)));
            current_statement_begin__ = 75;
            for (int i = 1; i <= N_ts; ++i) {

                current_statement_begin__ = 76;
                stan::math::assign(get_base1_lhs(X_pred,1,i,"X_pred",1), get_base1(X,1,i,"X",1));
                current_statement_begin__ = 77;
                stan::model::assign(X_pred, 
                            stan::model::cons_list(stan::model::index_min_max(2, get_base1(reps_ts,i,"reps_ts",1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), 
                            add(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (get_base1(reps_ts,i,"reps_ts",1) - 1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), "X"),multiply(R0,subtract(1,multiply(alpha,exp(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (get_base1(reps_ts,i,"reps_ts",1) - 1)), stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list())), "X")))))), 
                            "assigning variable X_pred");
                current_statement_begin__ = 79;
                if (as_bool(logical_lt(get_base1(reps_ts,i,"reps_ts",1),max_reps))) {

                    current_statement_begin__ = 80;
                    for (int j = (get_base1(reps_ts,i,"reps_ts",1) + 1); j <= max_reps; ++j) {
                        current_statement_begin__ = 80;
                        stan::math::assign(get_base1_lhs(X_pred,j,i,"X_pred",1), 0);
                    }
                }
            }

            // validate transformed parameters
            current_statement_begin__ = 66;
            check_greater_or_equal(function__,"R0",R0,0);
            current_statement_begin__ = 67;
            check_greater_or_equal(function__,"alpha",alpha,0);
            current_statement_begin__ = 68;
            check_greater_or_equal(function__,"process",process,0);
            current_statement_begin__ = 69;

            // write transformed parameters
        vars__.push_back(R0);
        vars__.push_back(alpha);
        vars__.push_back(process);
            for (int k_1__ = 0; k_1__ < N_ts; ++k_1__) {
                for (int k_0__ = 0; k_0__ < max_reps; ++k_0__) {
                vars__.push_back(X_pred(k_0__, k_1__));
                }
            }

            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_one_line";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_process";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "process";
        param_names__.push_back(param_name_stream__.str());
        for (int k_1__ = 1; k_1__ <= N_ts; ++k_1__) {
            for (int k_0__ = 1; k_0__ <= max_reps; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "X_pred" << '.' << k_0__ << '.' << k_1__;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_process";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "process";
        param_names__.push_back(param_name_stream__.str());
        for (int k_1__ = 1; k_1__ <= N_ts; ++k_1__) {
            for (int k_0__ = 1; k_0__ <= max_reps; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "X_pred" << '.' << k_0__ << '.' << k_1__;
                param_names__.push_back(param_name_stream__.str());
            }
        }

        if (!include_gqs__) return;
    }

}; // model

}

typedef model_one_line_namespace::model_one_line stan_model;


#endif