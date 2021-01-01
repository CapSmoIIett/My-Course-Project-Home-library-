#pragma once

#include <stack>

#include "tree.h"
#include "reading.h"
#include "scbooks.h"
#include "artbooks.h"
#include "magazines.h"
#include "newspapers.h"

class Act
{
private:
    bool action;            // 0 - удаление, 1 - добавление
    bool change;            // Это было изменение? 1 - Да 0 - Нет
    int  type;              // Тип переменной

public:
    Act (int, bool, bool change = 0);
    virtual ~Act() { }

     enum types {SC = 1, ART, NEWS, MAG};

     friend void returnAction(stack<Act*>& stack);
};

class ActA : public Act
{
private:
    ARTBooks copy;          // Копия элемента
    tree<ARTBooks> *home;   // Указатель на родное дерево
public:
    ActA(ARTBooks c, tree<ARTBooks>* h, int t, bool a, bool ch = 0);
    virtual ~ActA() { }
    ARTBooks getCopy();
    friend void returnAction(stack<Act*>& stack);
};

class ActS : public Act
{
private:
    SCBooks copy;          // Копия элемента
    tree<SCBooks> *home;   // Указатель на родное дерево
public:
    ActS(SCBooks c, tree<SCBooks>* h, int t, bool a, bool ch = 0);
    virtual ~ActS() { }
    friend void returnAction(stack<Act*>& stack);
};
class ActN : public Act
{
private:
    Newspapers copy;          // Копия элемента
    tree<Newspapers> *home;   // Указатель на родное дерево
public:
    ActN(Newspapers c, tree<Newspapers>* h, int t, bool a, bool ch = 0);
    virtual ~ActN() { }
    friend void returnAction(stack<Act*>& stack);
};

class ActM : public Act
{
private:
    Magazines copy;          // Копия элемента
    tree<Magazines> *home;   // Указатель на родное дерево
public:
    ActM(Magazines c, tree<Magazines>* h, int t, bool a, bool ch = 0);
    virtual ~ActM() { }
    friend void returnAction(stack<Act*>& stack);
};





void addActionStack(stack<Act*>&, ARTBooks, tree<ARTBooks>*, bool, bool c = 0);           // Добавление в стек действий
void addActionStack(stack<Act*>&, SCBooks , tree<SCBooks >*, bool, bool c = 0);
void addActionStack(stack<Act*>&, Newspapers, tree<Newspapers>*, bool, bool c = 0);
void addActionStack(stack<Act*>&, Magazines , tree<Magazines >*, bool, bool c = 0);

void returnAction(stack<Act*>&);                                                           // откат действия
//#include "act.inl"

