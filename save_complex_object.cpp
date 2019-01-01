// SAVING HIERARCHICAL OBJECT
// Berent Lunde

// C++
// Hierarchical object:
// Fields
// - node with pointer to child node
// - key
// - SetKey
// Methods
// Constructor
// GetKey
// createChild
// getChild
// saveNode

// laodNode (method or function of its own?)
// 
// Rcpp modules to load to R

// R
// create new node object
// set key
// createChild with key
// Save object
// rm objects
// load objects
// check if restored properly


#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x * 2;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
timesTwo(42)
*/
