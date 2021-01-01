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
#include <QCalendarWidget>

#include "magazines.h"
#include "excep.h"

class WindowMag : public QDialog
{
private:
    Magazines   *mag;

    QVBoxLayout *left;               // Разделители
    QVBoxLayout *right;
    QHBoxLayout *top;
    QHBoxLayout *bot;
    QVBoxLayout *all;

    QLabel      *_lName;             // Ярлыки
    QLabel      *_lDate;
    QLabel      *_lSub;
    QLabel      *_lPage;
    QLabel      *_lTop;
    QLineEdit   *lName;              // Поле ввода названия
    QLineEdit   *lDate;              // Поле ввода автора
    QLineEdit   *lSub;               // Поле ввода жанра
    QLineEdit   *lPage;
    QLineEdit   *lTop;

    QCalendarWidget *calendar;

private slots:
    void changeabook();             // Измение журнала

public:
    WindowMag(Magazines&);          // Конструктор

    QPushButton *bOk;               // Кнопки выбора
    QPushButton *bCl;
};

