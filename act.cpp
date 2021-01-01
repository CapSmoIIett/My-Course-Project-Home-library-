#include "act.h"

/* Конструкторы */
Act::Act(int t ,bool a, bool ch):
action(a),
change(ch),
type(t)
{ }
ActA::ActA(ARTBooks c, tree<ARTBooks>* h, int t, bool a, bool ch) :
Act(t, a, ch),
copy (c),
home (h)
{ }
ActS::ActS(SCBooks c, tree<SCBooks>* h, int t, bool a, bool ch):
Act(t, a, ch),
copy (c),
home (h)
{ }
ActN::ActN(Newspapers c, tree<Newspapers>* h, int t, bool a, bool ch) :
Act(t, a, ch),
copy (c),
home (h)
{ }
ActM::ActM(Magazines c, tree<Magazines>* h, int t, bool a, bool ch) :
Act(t, a, ch),
copy (c),
home (h)
{ }

/* Добавление в стек действий */
void addActionStack(stack<Act*>& s, ARTBooks b, tree<ARTBooks>* t, bool a, bool c)
{
    ActA* temp = new ActA(b, t, 2, a, c);
    s.push(temp);
}
void addActionStack(stack<Act*>& s, SCBooks b, tree<SCBooks >* t, bool a, bool c)
{
    ActS* temp = new ActS(b, t, 1, a, c);
    s.push(temp);
}
void addActionStack(stack<Act*>& s, Newspapers b, tree<Newspapers>* t, bool a, bool c)
{
    ActN* temp = new ActN(b, t, 3, a, c);
    s.push(temp);
}
void addActionStack(stack<Act*>& s, Magazines b, tree<Magazines >* t, bool a, bool c)
{
    ActM* temp = new ActM(b, t, 4, a, c);
    s.push(temp);
}

void returnAction(stack<Act*>& stack)       // отмена последнего действия
{
    Act* temp;
    if(stack.empty()) return;
    temp = stack.top();
    stack.pop();
    switch(Act::types(temp->type))          // Выбор типа книги
    {
    case Act::ART:
    {
        ActA* temp2 = dynamic_cast<ActA*>(temp);
        if(temp2->action)                   // Если книгу добавили
        {
            temp2->home->remove(temp2->copy);// удаляем ее
        }
        else
        {
            temp2->home->add(temp2->copy);   // если мы ее удалили, то добавлеям
        }
        break;
    }
    case Act::SC:
    {
        ActS* temp2 = dynamic_cast<ActS*>(temp);
        if(temp2->action)
        {
            temp2->home->remove(temp2->copy);
        }
        else
        {
            temp2->home->add(temp2->copy);
        }
        break;
    }
    case Act::NEWS:
    {
        ActN* temp2 = dynamic_cast<ActN*>(temp);
        if(temp2->action)
        {
            temp2->home->remove(temp2->copy);
        }
        else
        {
            temp2->home->add(temp2->copy);
        }
        break;
    }
    case Act::MAG:
    {
        ActM* temp2 = dynamic_cast<ActM*>(temp);
        if(temp2->action)
        {
            temp2->home->remove(temp2->copy);
        }
        else
        {
            temp2->home->add(temp2->copy);
        }
        break;
    }
    }
}

