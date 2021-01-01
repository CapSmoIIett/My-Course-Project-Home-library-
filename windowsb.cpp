#include "windowsb.h"

WindowSB::WindowSB(SCBooks& element)
{
    book   = & element;
    left   = new QVBoxLayout;              // Разделители
    right  = new QVBoxLayout;
    top    = new QHBoxLayout;
    all    = new QVBoxLayout(this);
    _lName = new QLabel("Name");           // Ярлыки
    _lAuth = new QLabel("Author");
    _lSect = new QLabel("Section");
    _lPage = new QLabel("Pages");
    _lTop  = new QLabel("Top");
    lName  = new QLineEdit;                // Поле ввода названия
    lAuth  = new QLineEdit();              // Поле ввода автора
    lSect  = new QLineEdit();              // Поле ввода жанра
    lPage  = new QLineEdit();
    lTop   = new QLineEdit();

    bOk    = new QPushButton("Ok");        // Кнопки выбора
    bCl    = new QPushButton("Cancel");

    lName->setPlaceholderText(QString::fromUtf8(element.getName().c_str()));        // fromUtf8 конвертирует Си строку в Qstring
    lAuth->setPlaceholderText(QString::fromUtf8(element.getAuth().c_str()));
    lSect->setPlaceholderText(QString::fromUtf8(element.getSection().c_str()));
    lPage->setPlaceholderText(QString::number(element.getPages()));
    lTop->setPlaceholderText(QString::number(element.getTop()));

    // Подключение слотов к сигналам
    connect(bCl, &QPushButton::clicked, this, &QDialog::close);
    connect(bOk, &QPushButton::clicked, this, &WindowSB::changeabook);

    left->addWidget(_lName);                            // Связывание
    left->addWidget(_lAuth);
    left->addWidget(_lSect);
    left->addWidget(_lPage);
    left->addWidget(_lTop);
    left->addWidget(bCl);
    right->addWidget(lName);
    right->addWidget(lAuth);
    right->addWidget(lSect);
    right->addWidget(lPage);
    right->addWidget(lTop);
    right->addWidget(bOk);
    top->insertLayout(0, left);
    top->insertLayout(1, right);
    all->insertLayout(0, top);

    this->setWindowTitle("Scientific Book");
}

void WindowSB::changeabook()
{
    try{
        if(lName->text() != "" && checkString((lName->text()).toUtf8().constData()))        // Если строка не пуста и строка верна
            book->setName((lName->text()).toUtf8().constData());                            // заносим строку в элемент
    }
    catch(Exception& a){
       lName->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
       return;
    }
    try{
        if(lAuth->text() != "" && checkString((lAuth->text()).toUtf8().constData()))        // Если строка не пуста и строка верна
            book->setAuth((lAuth->text()).toUtf8().constData());                            // заносим строку в элемент
    }
    catch(Exception& a){
       lAuth->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
       return;
    }
    try{
        if(lSect->text() != "" && checkString((lSect->text()).toUtf8().constData()))        // Если строка не пуста и строка верна
            book->setSection((lSect->text()).toUtf8().constData());                         // заносим строку в элемент
    }
    catch(Exception& a){
       lSect->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
       return;
    }
    try{
        if(lPage->text() != "" && checkString((lPage->text()).toUtf8().constData()) &&      // Если строка не пуста и строка верна
           stringWithInt  ((lPage->text()).toUtf8().constData()))                           // и она состоит только из чисел
           book->setPages((lPage->text()).toInt());                                         // заносим строку в элемент
    }
    catch(Exception& a){
       lPage->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
       return;
    }
    try{
        if(lTop->text()  != "" && checkString((lTop->text()).toUtf8().constData()) &&       // Если строка не пуста и строка верна
           stringWithInt((lTop->text()).toUtf8().constData()) &&                            // и она состоит только из чисел
           checkNumber  ((lTop->text()).toInt(), book->getPages()))                         // и страница закладки не больше количества страниц
           book->setTop ((lTop->text()).toInt());                                           // заносим строку в элемент
    }
    catch(Exception& a){
        lTop->setText(QString::fromUtf8(a.what().c_str()));
        return;
    }
    this->close();
}

