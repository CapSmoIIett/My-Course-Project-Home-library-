#pragma once
#include <QMainWindow>
#include <QFileSystemModel>
#include <QToolBar>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QLineEdit>
#include <QListWidget>
#include <QLayout>
#include <QStatusBar>
#include <QtGui>

#include "filestream.h"
#include "act.h"
#include "tree.h"
#include "reading.h"
#include "scbooks.h"
#include "artbooks.h"
#include "magazines.h"
#include "newspapers.h"
#include "addbwindow.h"
#include "windowab.h"
#include "windowsb.h"
#include "windowmag.h"
#include "windownews.h"

#include "conditions.inl"


class MWindow : public QMainWindow
{
    Q_OBJECT

private:
    tree<SCBooks> tree_scb;         // Деревья книг
    tree<ARTBooks> tree_artb;
    tree<Magazines> tree_mag;
    tree<Newspapers> tree_news;

    stack<Act*> actionStack;        // стек действий

    QToolBar *tools;                // Элементы интерфейса
    QToolBar *tools2;
    QListWidget *list;
    QLineEdit   *search;
    QLabel* status;

    enum trees {SC = 1, ART, NEWS, MAG};
    unsigned current_tree;          // ТИп текущего дерева

    void createMenuBar();           // Создание элементов интерфейса
    void createToolBar();
    void createToolBar2();
    void createBookList();
    void createStatusBar();

    template<class T>
    void printtree(tree<T>&, QListWidget*); // Печать дерева в список

    void saveInFile();              // Сохранить в файл
    void loadFromFile();

private slots:
    void addReading();              // Добавить книгу
    void WatchArtBook();            // Просмотреть список
    void WatchSciBook();
    void WatchMagazines();
    void WatchNewspapers();
    void setABook();                // Изменение книги
    void setSBook();
    void setNewsp();
    void setMagazines();
    void updateListSlot();          // Обновить список
    void saveInFileSlot();          // Сохранить в файл
    void changeConditionNameAZ();   // Изменение условия в деревьях
    void changeConditionNameZA();
    void changeConditionPagesIncr();
    void changeConditionPagesDecr();
    void customMenuSlot(QPoint);
    void deleteElementList();
    void undoActionSlot();
    void searchSlot();
    void setStatusDefault();
    void errorGet(std::string);

public:
    MWindow(QWidget *parent = nullptr); // Конструктор
    ~MWindow();

    void updateList(unsigned type = 0); // Обновление списка
    void setStatusBar(std::string);     // УСтановка строки состояния

};
