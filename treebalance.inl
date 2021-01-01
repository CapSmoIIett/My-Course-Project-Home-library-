#include "tree.h"

using namespace std;

template <class T>
node<T>::node(T d, node<T>* t, node<T>* l, node<T>* r, unsigned int  h) : 
data(d), top(t), left(l),
right(r), height(h)
{ }
