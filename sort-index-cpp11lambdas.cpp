#include <Rcpp.h>

// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins("cpp11")]]


using namespace Rcpp;
using namespace std;

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {
    
    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    
    // sort indexes based on comparing values in v
    sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});
    
    return idx;
}

// [[Rcpp::export]]
void sorted(vector<double> v){
    for (auto i: sort_indexes(v)) {
        cout << v[i] << endl;
    }
}

/*** R
sorted((10:1)+0.5)
*/
