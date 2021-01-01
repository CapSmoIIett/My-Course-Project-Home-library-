#include "addbwindow.h"
#include "act.h"

AddBWindow::AddBWindow(tree<ARTBooks>& a,tree<SCBooks>& s,tree<Newspapers>& n, tree<Magazines>& m, stack<Act*>& st)
{
    ABooks = &a;
    SBooks = &s;
    News   = &n;
    Mag    = &m;
    actionStack = &st;

    top    = new QHBoxLayout;              // Разделители
    bot    = new QHBoxLayout;
    all    = new QVBoxLayout(this);
    lName  = new QLabel("Name");           // Ярлык
    line   = new QLineEdit();              // Поле ввода имени
    box    = new QComboBox;
    bOk    = new QPushButton("Ok");        // Кнопки выбора
    bCl    = new QPushButton("Cancel");

    box->addItem("Art book");              // Установка полей
    box->addItem("Science book");
    box->addItem("Newspapers");
    box->addItem("Magazines");
                                           // Подключение слотов к сигналам
    connect(bCl, &QPushButton::clicked, this, &AddBWindow::close);
    connect(bOk, &QPushButton::clicked, this, &AddBWindow::addBook);

    top->addWidget(lName);                 // Связывание
    top->addWidget(line);
    bot->addWidget(box);
    bot->addWidget(bCl);
    bot->addWidget(bOk);
    all->insertLayout(0, top);
    all->insertLayout(1, bot);
}

void AddBWindow::addBook()
{

    switch((box->currentText()).toUtf8().constData()[0])      // выбор по первому символу в combobox
    {
    case('A'):
    {
        ARTBooks temp;
        try{
            if(line->text() != "" && checkString((line->text()).toUtf8().constData()))         // Если строка не пуста и строка верна
                temp.setName((line->text()).toUtf8().constData());                             // заносим строку в элемент
        }
        catch(Exception& a){
           line->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
           return;
        }
        ABooks->add(temp);
        addActionStack(*actionStack, temp, ABooks, 1);                                         // Добавление в стек действия
        break;
    }
    case('S'):
    {
        SCBooks temp;
        try{
            if(line->text() != "" && checkString((line->text()).toUtf8().constData()))         // Если строка не пуста и строка верна
                temp.setName((line->text()).toUtf8().constData());                             // заносим строку в элемент
        }
        catch(Exception& a){
           line->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
           return;
        }
        SBooks->add(temp);
        addActionStack(*actionStack, temp, SBooks, 1);                                         // Добавление в стек действия
        break;
    }
    case('N'):
    {
        Newspapers temp;
        try{
            if(line->text() != "" && checkString((line->text()).toUtf8().constData()))         // Если строка не пуста и строка верна
                temp.setName((line->text()).toUtf8().constData());                             // заносим строку в элемент
        }
        catch(Exception& a){
           line->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
           return;
        }
        News->add(temp);
        addActionStack(*actionStack, temp, News, 1);                                           // Добавление в стек действия
        break;
    }
    case('M'):
    {
        Magazines temp;
        try{
            if(line->text() != "" && checkString((line->text()).toUtf8().constData()))         // Если строка не пуста и строка верна
                temp.setName((line->text()).toUtf8().constData());                             // заносим строку в элемент
        }
        catch(Exception& a){
           line->setText(QString::fromUtf8(a.what().c_str()));                                 // Пишем ошибку в поле ввода
           return;
        }
        Mag->add(temp);
        addActionStack(*actionStack, temp, Mag, 1);                                            // Добавление в стек действия
        break;
    }
    }
    this->close();
}
