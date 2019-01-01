#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double timesTwo(double x) {
  return x * 2;
}

// function that takes a function pointer
// warning: cannot be returned to R
// -- internal in C++ only
// -- Use xptr (function_pointer example) if return to R
double funCall(double x, double(*fun)(double)){
    return fun(x);
}

// [[Rcpp::export]]
double mfun(double x){
    
    double res = funCall(x, timesTwo);
        
    return res;
}


/*** R
timesTwo(42)
mfun(42)
*/
