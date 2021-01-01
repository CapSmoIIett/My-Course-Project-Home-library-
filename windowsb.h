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

#include "scbooks.h"
#include "excep.h"

class WindowSB : public QDialog
{
private:
    SCBooks     *book;
    QVBoxLayout *left;          // Разделители
    QVBoxLayout *right;
    QHBoxLayout *top;
    QVBoxLayout *all;

    QLabel      *_lName;        // Ярлыки
    QLabel      *_lAuth;
    QLabel      *_lSect;
    QLabel      *_lPage;
    QLabel      *_lTop;
    QLineEdit   *lName;         // Поле ввода названия
    QLineEdit   *lAuth;         // Поле ввода автор
    QLineEdit   *lSect;         // Поле ввода жанра
    QLineEdit   *lPage;
    QLineEdit   *lTop;

private slots:
    void changeabook();         // Изменение книги

public:
    WindowSB(SCBooks&);         // Конструктор

    QPushButton *bOk;           // Кнопки выбора
    QPushButton *bCl;
};
