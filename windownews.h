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

#include "newspapers.h"
#include "excep.h"

class WindowNews : public QDialog
{
private:
    Newspapers  *news;

    QVBoxLayout *left;               // Разделители
    QVBoxLayout *right;
    QHBoxLayout *top;
    QHBoxLayout *bot;
    QVBoxLayout *all;

    QLabel      *_lName;             // Ярлыки
    QLabel      *_lDate;
    QLabel      *_lLoc;
    QLabel      *_lPage;
    QLabel      *_lTop;
    QLineEdit   *lName;              // Поле ввода названия
    QLineEdit   *lDate;              // Поле ввода автора
    QLineEdit   *lLoc;               // Поле ввода жанра
    QLineEdit   *lPage;
    QLineEdit   *lTop;

    QCalendarWidget *calendar;

private slots:
    void changeabook();              // Измение газеты

public:
    WindowNews(Newspapers&);         // Конструктор

    QPushButton *bOk;                // Кнопки выбора
    QPushButton *bCl;
};
