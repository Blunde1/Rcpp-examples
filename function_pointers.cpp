#include <RcppArmadillo.h>


// [[Rcpp::depends(RcppArmadillo)]]

using namespace arma; 
using namespace Rcpp;

typedef vec (*funcPtr)(const vec& x);

vec fun1_cpp(const vec& x) {	// a first function 
    vec y = x + x;
    return (y);
}

vec fun2_cpp(const vec& x) {	// and a second function
    vec y = 10*x;
    return (y);
}

// [[Rcpp::export]]
XPtr<funcPtr> putFunPtrInXPtr(std::string fstr) {
    if (fstr == "fun1")
        return(XPtr<funcPtr>(new funcPtr(&fun1_cpp)));
    else if (fstr == "fun2")
        return(XPtr<funcPtr>(new funcPtr(&fun2_cpp)));
    else
        return XPtr<funcPtr>(R_NilValue); // runtime error as NULL no XPtr
}

// [[Rcpp::export]]
vec callViaString(const vec x, std::string funname) {
    XPtr<funcPtr> xpfun = putFunPtrInXPtr(funname);
    funcPtr fun = *xpfun;
    vec y = fun(x);
    return (y);
}

// [[Rcpp::export]]
vec callViaXPtr(const vec x, SEXP xpsexp) {
    XPtr<funcPtr> xpfun(xpsexp);
    funcPtr fun = *xpfun;
    vec y = fun(x);
    return (y);
}


/***R
callViaString(1:3, "fun1")
callViaString(1:3, "fun2")
fun <- putFunPtrInXPtr("fun1")
callViaXPtr(1:4, fun)
*/