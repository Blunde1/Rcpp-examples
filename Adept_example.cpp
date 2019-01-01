#include <RcppEigen.h>
#include "Eigen/Dense"
#include "adept.h"
#include "adept_source.h"
#include <math.h>
using namespace Eigen;
using namespace std;
using namespace Rcpp;
using adept::adouble;
typedef adept::adouble adtype;

//template <class T>
//using Tmat = Eigen::Matrix<T,Dynamic,Dynamic>;

//template <class T>
//using Tvec = Eigen::Matrix<T,Dynamic,1>;

/////////////////////////////

// [[Rcpp::export]]
Rcpp::List Adept_test(double x, double y, int n_u)
{
  adept::Stack stack;
  adtype ad_x = x;
  adtype ad_y = y;

  stack.new_recording();

  adtype res0 = 2*pow(x,2)+4*y;
  adtype res = res0/1.0;

  res.set_gradient(1.0);
  stack.compute_adjoint();

  double xgrad = ad_x.get_gradient();
  double ygrad = ad_y.get_gradient();

  return Rcpp::List::create(
    Named("xgrad")  = xgrad,
    Named("ygrad")  = ygrad);

}




