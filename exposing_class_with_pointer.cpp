#include <Rcpp.h>
using namespace Rcpp;

class node
{
private:

    double value; // Voluntarily hidden from R
    node* child; // Must be hidden from R
    
public:
    
    // Exposed functions
    void setVal(double value);
    double getVal();
    
    node* createNode(double value); // return pointer to a node
    node* createChild(double value); // set child
    node* getChild();
    
};

void finalizer_of_node( node* ptr ){
    printf("finalizer has been called\n");
}

void node::setVal(double value){
    this->value = value;
}
double node::getVal(){
    return this->value;
}

node* node::createNode(double value){
    node* n = new node;
    n->value = value;
    return n;
}
node* node::createChild(double value){
    this->child = createNode(value);
    return child;
}
node* node::getChild(){
    return this->child;
}


RCPP_MODULE(gbtree_module){
    using namespace Rcpp;
    class_<node>("node")
        .constructor()
      .method("setVal", &node::setVal)
      .method("getVal", &node::getVal)
      .method("createNode", &node::createNode)
      .method("createChild", &node::createChild)
      .method("getChild", &node::getChild)
      .finalizer( &finalizer_of_node )
    ;
}
/*** R
if(F){
n <- new(node)
n$setVal(1)
n$getVal()
n2 <- n$createNode(1) # unrelated node
n3 <- n$createChild(3) #child node
n$getChild() #pointer to child node
n3
rm(n)
gc()
rm(n2)
gc()
rm(n3)
gc()
rm(n, n2, n3)
gc()
}
*/
