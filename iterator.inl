#include "tree.h"

template<class T>                                                           //Конструктор
_iterator<T>::_iterator() {}
template< class T>
_iterator<T>::_iterator(node<T> *p) : pointer(p) {}                         //Конструктор
template< class T>
_iterator<T>::_iterator(const _iterator &it) : pointer(it.pointer) {}       //Конструкторера
/* Перегруженные операторы*/
template <class T>
_iterator<T>& _iterator<T>::operator=(const _iterator &it)
{
    pointer = it.pointer;
    return *this;
}
template <class T>
_iterator<T>& _iterator<T>::operator++(int)
{
    auto temp = pointer;
    if (pointer->right != nullptr)
    {
        pointer = pointer->right;
        while (pointer->left != nullptr)
            pointer = pointer->left;
        return *this;
    }
    else
    {
        do
        {
            temp = pointer;
            pointer = pointer->top;
        } while (pointer != nullptr && pointer->right == temp);
    }
    return *this;
}
template <class T>
_iterator<T>& _iterator<T>::operator++()
{
    auto temp = pointer;
    if (pointer->right != nullptr)
    {
        pointer = pointer->right;
        while (pointer->left != nullptr)
            pointer = pointer->left;
        return *this;
    }
    else
    {
        do
        {
            temp = pointer;
            pointer = pointer->top;
        } while (pointer != nullptr && pointer->right == temp);
    }
    return *this;
}
template <class T>
_iterator<T>& _iterator<T>::operator--(int)
{
    auto temp = pointer;
    if (pointer->left != nullptr)
    {
        pointer = pointer->left;
        while (pointer->right != nullptr)
            pointer = pointer->right;
        return *this;
    }
    else
    {
        do
        {
            temp = pointer;
            pointer = pointer->top;
        } while (pointer != nullptr && pointer->left == temp);
    }
    return *this;
}
template <class T>
T& _iterator<T>::operator*()
{
    //if (pointer == nullptr); // throw std::exception();
    return pointer->data;
}
template <class T>
bool _iterator<T>::operator!=(const _iterator<T> &it)
{
    if (pointer != it.pointer)
        return 1;
    return 0;
}
template <class T>
bool _iterator<T>::operator==(const _iterator<T> &it)
{
    if (pointer->data == it.pointer->data)
        return 1;
    return 0;
}
