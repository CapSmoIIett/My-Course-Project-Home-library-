#include "tree.h"

template <class T>
tree<T>::tree()                 // Конструкторы
{
    condition = &_condition;
    root = nullptr;
}

template <class T>
tree<T>::tree(T t)
{
    root = new node<T>(t);
    condition = &_condition;
}
template <class T>
tree<T>::~tree()
{
    while (root != nullptr)
        remove(root);
}
template <class T>
void tree<T>::add(T t)              //Добавление
{
    root = _add(t, root);
}

template <class T>
node<T>* tree<T>::_add(T t, node<T>* point, node<T>* prepoint)
{
    if(point == nullptr) point = new node<T>(t, prepoint);
    else if (t == point->data) return point;
    else if (this->condition(t, point->data)) point->right = _add(t, point->right, point);
    else if (!this->condition(t, point->data)) point->left = _add(t, point->left, point);
    return point;
}

template <class T>
void tree<T>::remove(iterator it)   // Удаление
{
    remove(it.pointer);
}

template <class T>
void tree<T>::remove(node<T>* pointer)
{
    node<T>* temp_l;
    node<T>* temp_r;
    node<T>* temp_t;
    node<T>* temp;

    if (pointer == nullptr) return;             // Если null
    else if (pointer == root){                       // Если корень
        if(pointer->left != nullptr)           // Если левый указатель не null
        {
            temp_l = pointer->left;    
            temp = temp_l;                      
            while(temp->right != nullptr){      // то идем от левого к самому большому 
                temp = temp->right;
            }
            temp->right = pointer->right;       // связываем правый от pointer к самому большому слева
            if(pointer->right != nullptr) pointer->right->top = temp;
            temp_l->top = nullptr;
            root = temp_l;
            delete pointer;
        }
        else if (pointer->right != nullptr)    // Если правый указатель не null а левый null
        {
            temp_r = pointer->right;
            temp = temp_r;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            temp->left = pointer->left;
            temp_r-> top = nullptr;
            root = temp_r;
            delete pointer;
        } 
        else
        {
            delete pointer;
            root = nullptr;
        }
    }
    else                                        // Когда это просто узел
    {                           
        if(pointer->left != nullptr)           // Если левый указатель не null
        {
            temp_l = pointer->left;    
            temp = temp_l;                      
            while(temp->right != nullptr){      // то идем от левого к самому большому 
                temp = temp->right;
            }
            temp->right = pointer->right;       // связываем правый от pointer к самому большому слева
            if(pointer->right != nullptr) pointer->right->top = temp;

            temp_t = pointer->top;              // связываем вверха
            temp_l->top = temp_t;
            if(temp_t->right == pointer) temp_t->right = temp_l;
            else temp_t->left = temp_l;
            delete pointer;
        }
        else if (pointer->right != nullptr)    // Если правый указатель не null а левый null
        {
           temp_r = pointer->right;
            temp = temp_r;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            temp->left = pointer->left;
            temp_t = pointer->top;              
            temp_r->top = temp_t;
            if(temp_t->right == pointer) temp_t->right = temp_r;
            else temp_t->left = temp_r;
            delete pointer;
        }
        else
        {
            temp_t = pointer->top;
            if(temp_t->right == pointer) temp_t->right = nullptr;
            else temp_t->left = nullptr;
            delete pointer;
        } 
    }
}

template <class T>
void tree<T>::remove(T t)   // Удаление
{
    remove(_find(t, root));
}

template <class T>
void tree<T>::show(){       // Печать дерева
    _show(root);
}

template <class T>
void tree<T>::_show(node<T>* point){
    if (point == nullptr) return;

    _show(point->left);
    std::cout << point->data << std::endl;
    _show(point->right);
}

template <class T>
node<T>* tree<T>::find(T t)
{
    return _find(t, root);
}
template <class T>
_iterator<T> tree<T>::find2(T t)
{
    _iterator<T> a (_find(t,root));
    return a;
}
template <class T>
node<T>* tree<T>::_find(T t, node<T>* point)
{
    if(point == nullptr) return nullptr;
    else if (t == point->data) return point;
    else if (this->condition(t, point->data)) return _find(t, point->right);            //ЗДЕСЬ ВЫБИВАЕТ ОШИБКУ. В ТОЧКУ ПРИХОДИТ НЕСКОЛЬКО РАз
    else if (!this->condition(t, point->data)) return _find(t, point->left);
    return nullptr;
}




template<class T>
typename tree<T>::iterator tree<T>::begin()
{
    if (root == nullptr) return iterator(nullptr);
    return _begin(root);
}

template<class T>
typename tree<T>::iterator tree<T>::_begin(node<T>* pointer)
{
    if (pointer->left == nullptr) return iterator(pointer);
    return _begin(pointer->left);
}
template<class T>

typename tree<T>::iterator tree<T>::end()
{
    return nullptr;
}

template<class T>
typename tree<T>::iterator tree<T>::rbegin()
{
    if (root == nullptr) return iterator(nullptr);
    return _rbegin(root);
}

template<class T>
typename tree<T>::iterator tree<T>::_rbegin(node<T>* pointer)
{
    if (pointer->right == nullptr) return iterator(pointer);
    return _rbegin(pointer->right);
}
template<class T>

typename tree<T>::iterator tree<T>::rend()
{
    return nullptr;
}




template <class T>
void tree<T>::set_condition (bool (*f) (T,T)){
    condition = f;
    node<T>* temp = nullptr;
    while (root != nullptr){
        temp = _add(root->data, temp);
        remove(root);
    }
    root = temp;
}

template <class T>
bool tree<T>::_condition(T t1, T t2){
        return t1 > t2;
}




template <class T>
tree<T>& tree<T>::operator= (tree<T>& another)
{
    if(this == &another) return *this;
    while(root != nullptr){
        this->remove(root);
    }
    node<T>* temp = nullptr;
    for(auto it = another.begin(); it != another.end(); it++){
        temp = _add(*it, temp);
    }
    root = temp;
    return *this;
}

template <class T>
_iterator<T> tree<T>::operator[](int num)
{
    if(num < 0) return end();
    int i = 0;
    for(auto it = begin(); it != end(); it++)
    {
        if(i == num) return it;
        i++;
    }
    return end();
}

