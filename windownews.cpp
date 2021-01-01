#include "windownews.h"

WindowNews::WindowNews(Newspapers& element)
{
    news   = &element;
    left   = new QVBoxLayout;              // Разделители
    right  = new QVBoxLayout;
    top    = new QHBoxLayout;
    bot    = new QHBoxLayout;
    all    = new QVBoxLayout(this);
    _lName = new QLabel("Name");           // Ярлыки
    _lPage = new QLabel("Pages");
    _lTop  = new QLabel("Top");
    _lLoc  = new QLabel("Location");
    lName  = new QLineEdit;                // Поле ввода названия
    lPage  = new QLineEdit();
    lTop   = new QLineEdit();
    lLoc   = new QLineEdit();              // Поле ввода жанра
    bOk    = new QPushButton("Ok");        // Кнопки выбора
    bCl    = new QPushButton("Cancel");

    calendar = new QCalendarWidget;

    lName->setPlaceholderText(QString::fromUtf8(element.getName().c_str()));        // fromUtf8 конвертирует Си строку в Qstring
    lPage->setPlaceholderText(QString::number(element.getPages()));
    lTop->setPlaceholderText(QString::number(element.getTop()));
    lLoc->setPlaceholderText(QString::fromUtf8(element.getLocation().c_str()));
    calendar->setSelectedDate(element.getTimeIssue().date());

    connect(bCl, &QPushButton::clicked, this, &QDialog::close);
    connect(bOk, &QPushButton::clicked, this, &WindowNews::changeabook);

    left->addWidget(_lName);                            // Связывание
    left->addWidget(_lPage);
    left->addWidget(_lTop);
    left->addWidget(_lLoc);
    left->addWidget(bCl);
    right->addWidget(lName);
    right->addWidget(lPage);
    right->addWidget(lTop);
    right->addWidget(lLoc);
    right->addWidget(bOk);
    top->insertLayout(0, left);
    top->insertLayout(1, right);
    bot->addWidget(calendar);
    all->insertLayout(0, top);
    all->insertLayout(1, bot);

    this->setWindowTitle("Newspaper");
}

void WindowNews::changeabook()
{
    try{
        if(lName->text() != "" && checkString((lName->text()).toUtf8().constData()))        // Если строка не пуста и строка верна
            news->setName((lName->text()).toUtf8().constData());                            // заносим строку в элемент
    }
    catch(Exception& a){
       lName->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
       return;
    }
    try{
        if(lPage->text() != "" && checkString((lPage->text()).toUtf8().constData()) &&      // Если строка не пуста и строка верна
           stringWithInt  ((lPage->text()).toUtf8().constData()))                           // и она состоит только из чисел
           news->setPages((lPage->text()).toInt());                                         // заносим строку в элемент
    }
    catch(Exception& a){
       lPage->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
       return;
    }
    try{
        if(lTop->text()  != "" && checkString((lTop->text()).toUtf8().constData()) &&       // Если строка не пуста и строка верна
           stringWithInt((lTop->text()).toUtf8().constData()) &&                            // и она состоит только из чисел
           checkNumber  ((lTop->text()).toInt(), news->getPages()))                         // и страница закладки не больше количества страниц
           news->setTop ((lTop->text()).toInt());                                           // заносим строку в элемент
    }
    catch(Exception& a){
        lTop->setText(QString::fromUtf8(a.what().c_str()));
        return;
    }
    try{
        if(lLoc->text()  != "" && checkString((lLoc->text()).toUtf8().constData()))         // Если строка не пуста и строка верна
           news->setTop ((lLoc->text()).toInt());                                           // заносим строку в элемент
    }
    catch(Exception& a){
        lLoc->setText(QString::fromUtf8(a.what().c_str()));
        return;
    }
    try{
        if(checkDate(calendar->selectedDate().endOfDay()))                                  // Проверяем верная ли дата
            news->setTimeIssue(calendar->selectedDate().endOfDay());
    }
    catch(Exception& a)
    {
        return;
    }

    this->close();
}
