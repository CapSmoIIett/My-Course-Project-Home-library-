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

#include "mwindow.h"
#include "artbooks.h"
#include "excep.h"

class WindowAB : public QDialog
{
private:
    ARTBooks    *book;

    QVBoxLayout *left;              // Разделители
    QVBoxLayout *right;
    QHBoxLayout *top;
    QVBoxLayout *all;

    QLabel      *_lName;           // Ярлыки
    QLabel      *_lAuth;
    QLabel      *_lGenr;
    QLabel      *_lPage;
    QLabel      *_lTop;
    QLineEdit   *lName;            // Поля ввода
    QLineEdit   *lAuth;
    QLineEdit   *lGenr;
    QLineEdit   *lPage;
    QLineEdit   *lTop;

private slots:
    void changeabook();            // Изменение книги

public:
    WindowAB(ARTBooks&);           // Конструктор

    QPushButton *bOk;              // Кнопки выбора
    QPushButton *bCl;
};
