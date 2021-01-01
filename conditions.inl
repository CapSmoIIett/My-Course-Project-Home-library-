#include "scbooks.h"
#include "artbooks.h"
#include "newspapers.h"

/* Условия деревьев*/

template <class T>
bool conditionNameAZ(T t1, T t2)
{
   return t1 > t2;
}
template <class T>
bool conditionNameZA(T t1, T t2)
{
   return t1 < t2;
}
template <class T>
bool conditionPagesIncr(T t1, T t2)
{
   return t1.pages > t2.pages;
}
template <class T>
bool conditionPagesDecr(T t1, T t2)
{
   return t1.pages < t2.pages;
}
