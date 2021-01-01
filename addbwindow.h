#pragma once
#include <QDialog>
#include <QMainWindow>
#include <QFileSystemModel>
#include <QToolBar>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QListWidget>
#include <QLayout>
#include <QStatusBar>
#include <QtGui>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QComboBox>

#include "tree.h"
#include "scbooks.h"
#include "artbooks.h"
#include "newspapers.h"
#include "magazines.h"
#include "act.h"
#include "excep.h"

class AddBWindow : public QDialog
{
private:
    QHBoxLayout *top;                   // Разделители
    QHBoxLayout *bot;
    QVBoxLayout *all;
    QLabel      *lName;                 // Ярлык
    QLineEdit   *line;                  // Поле ввода имени
    QComboBox   *box;

    tree<ARTBooks>      *ABooks;        // указатели на деревья книг
    tree<SCBooks>       *SBooks;
    tree<Newspapers>    *News;
    tree<Magazines>     *Mag;

    stack<Act*>         *actionStack;   // указатель на стек действий

private slots:
    void addBook();                     // Слот добваления книиги
public:
    AddBWindow(tree<ARTBooks>&,  tree<SCBooks>&,    //Конструктор
               tree<Newspapers>&, tree<Magazines>&, stack<Act*>&);



    QPushButton *bCl;            // Кнопки выбора
    QPushButton *bOk;
};

//#include "addbwindow.cpp"
