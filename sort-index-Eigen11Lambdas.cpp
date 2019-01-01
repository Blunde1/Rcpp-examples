#include <RcppEigen.h>
//#include "Eigen/Dense"

// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins("cpp11")]]

// Enables Eigen
// [[Rcpp::depends(RcppEigen)]]


using namespace Eigen;
using namespace Rcpp;
using namespace std;

template <class T>
using Tvec = Eigen::Matrix<T,Dynamic,1>;

template <typename T>
Tvec<size_t> sort_indexes(const Tvec<T> &v) {

    // Initialize
    Tvec<size_t> idx(v.size());
    iota(idx.data(), idx.data()+idx.size(), 0);
    
    // Sort with lambda functionality
    std::sort(idx.data(), idx.data() + idx.size(),
              [&v](int i1, int i2){return v[i1] < v[i2];});
    
    // Return
    return idx;
}


// [[Rcpp::export]]
void sorted(Tvec<double> v){
    
    auto idx = sort_indexes(v);
    
    // Using keyword auto -- works
    // for(auto it = idx.data(); it < idx.data()+idx.size(); ++it){
    //     cout << v[*it] << endl;
    // }
    
    for(int i=0; i<v.size(); i++){
        cout << v[idx[i]] << endl;
    }
    
}

/*** R
sorted((10:1)+0.5)
*/
