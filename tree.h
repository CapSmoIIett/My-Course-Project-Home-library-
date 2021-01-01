#pragma once

#include <iostream>
#include <exception>


template <class t>
class node;

template <class t>
class tree;

template <class D>
class _iterator                     // Итератор
{
private:
    node<D> *pointer;

public:
    _iterator();                    // Конструкторы
    _iterator(node<D> *p);
    _iterator(const _iterator &it);
    /* Перегруженные операторы*/
    _iterator &operator=(const _iterator &it);
    _iterator &operator++(int);
    _iterator &operator++();
    _iterator &operator--(int);
    D& operator*();
    bool operator!= (const _iterator &it);
    bool operator== (const _iterator &it);

    friend void tree<D>::remove(_iterator<D>);
};



template <class T>
class tree                                 // Класс дерева
{
private:
    node<T> *root;
    bool (*condition)(T, T);

public:

    typedef _iterator<T> iterator;

    tree();
    tree(T);
    ~tree();
    void add(T);                            // Добаление                                //B
    void remove(iterator);                  // Удаление (дружественна итератору)
    void remove(node<T>*);                  // Удаление                                 //B
    void remove(T);                         // Удаление
    void show();                            // Вывод
    void set_condition (bool (*f) (T,T));   // Задание нового условия

    tree<T>& operator= (tree<T>&);
    _iterator<T> operator[](int);

    _iterator<T> begin();                   // Для раоты с итератором
    _iterator<T> end();
    _iterator<T> rbegin();  
    _iterator<T> rend();

    node<T>* find(T t);                     // Поиск
    _iterator<T> find2(T t);                // Поиск возвращающий итератор

protected:
    node<T>* _add(T, node<T>* pointer, node<T>* prepointer = nullptr);
    node<T>* _find(T t, node<T>*);

    /* Вспомогательные функции */
    _iterator<T> _begin(node<T>*);
    _iterator<T> _rbegin(node<T>*);
    void _copy(node<T>* point);
    void _show(node<T>* point);
    void _setroot(node<T>* p){root = p;}
    static bool _condition(T t1, T t2);
};



template <class T>
class node                              // Узел
{
    friend class tree<T>;
    friend class _iterator<T>;
private:
    T data;
    unsigned int height;
    node<T> *top;                       // указатели на соседнии узлы
    node<T> *left;
    node<T> *right;

    T getvalue() const {return data;};  // Взятие значения

public:
    node(T, node* top = nullptr, node* left = nullptr,  // Конструктор
            node* right = nullptr,unsigned int  hight = 1);
};

#include "tree.inl"
#include "treebalance.inl"
#include "iterator.inl"
