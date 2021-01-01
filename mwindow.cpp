#include "mwindow.h"

MWindow::MWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loadFromFile();         // Загружаем книги
    createMenuBar();        // Создаем меню
    createToolBar2();       // Создаем панель инструментов
    addToolBarBreak();      // Разделение панелей инструментов
    createToolBar();        // Создаем  вторую панель инструментов
    createBookList();       // Создаем список книг
    createStatusBar();      // Создаем строку состояния
    this->resize(430, 800);
    this->setWindowTitle("YourLib");
}
MWindow::~MWindow()
{
    saveInFile();
}
void MWindow::createMenuBar()
{
    QMenu *menu;
    menu = menuBar()->addMenu("&File");                         // Создаем пункт в меню
    QAction* open = menu->addAction("&Add");                    // добавляемв в него элементы
    QAction* save = menu->addAction("&Save");

    QObject::connect(open, &QAction::triggered, this, &MWindow::addReading);    // связываем элементы с слотами
    QObject::connect(save, &QAction::triggered, this, &MWindow::saveInFileSlot);

    menu = menuBar()->addMenu("&Sort");                         // Создаем пункт в меню
    QAction* nameAZ = menu->addAction("&by Name (a-z)");        // добавляемв в него элементы
    QAction* nameZA = menu->addAction("&by Name (z-a)");
    QAction* pagesI = menu->addAction("&by Pages (increase)");
    QAction* pagesD = menu->addAction("&by Pages (decrease)");
    connect(nameAZ, &QAction::triggered, this, &MWindow::changeConditionNameAZ);    // связываем элементы с слотами
    connect(nameZA, &QAction::triggered, this, &MWindow::changeConditionNameZA);
    connect(pagesI, &QAction::triggered, this, &MWindow::changeConditionPagesIncr);
    connect(pagesD, &QAction::triggered, this, &MWindow::changeConditionPagesDecr);
}
void MWindow::createToolBar()
{
    tools = addToolBar("main toolbar");                        // Создаем панель инструментов
    QAction  *sc    = tools->addAction("&Scientific Books");   // добавляемв в него элементы
    QAction  *art   = tools->addAction("&Art Books");
    QAction  *news  = tools->addAction("&Newspapers");
    QAction  *mag   = tools->addAction("&Magazines");

    QObject::connect(sc  , &QAction::triggered, this, &MWindow::setSBook); // связываем элементы с слотами
    QObject::connect(art , &QAction::triggered, this, &MWindow::setABook);
    QObject::connect(news, &QAction::triggered, this, &MWindow::setNewsp);
    QObject::connect(mag , &QAction::triggered, this, &MWindow::setMagazines);


}
void MWindow::createToolBar2()
{
    tools2 = addToolBar("second toolbar");              // Создаем панель инструментов
    QAction *undo = tools2->addAction("&undo");         // добавляемв в него элементы
    search  = new QLineEdit;

    connect(undo, &QAction::triggered, this, &MWindow::undoActionSlot); // связываем элементы с слотами
    connect(search, &QLineEdit::textChanged, this, &MWindow::searchSlot);
    tools2->addWidget(search);
}
void MWindow::createBookList()
{
    list = new QListWidget;                             // Создаем список книг
    list->setContextMenuPolicy(Qt::CustomContextMenu);
    printtree<ARTBooks>(tree_artb, list);               // Печатаем в список дерево
    current_tree = trees(ART);                          // Устанавливаем сосояние текущего дерева

    connect(list, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customMenuSlot(QPoint)));  // Добавляем слот контекстного меню
    connect(list, &QListWidget::doubleClicked, this, &MWindow::WatchArtBook );

    list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);    // Добавляем полосу прокрутки
    setCentralWidget(list);                                     // Делаем список - центром приложения
}
void MWindow::createStatusBar()
{
    status = new QLabel(" No file select ");                    // Делаем ярлык для строки состояния
    status->setAlignment(Qt::AlignCenter);                      // Настраиваем текст ярлыка
    status->setMinimumSize(status->sizeHint());
    statusBar()->addWidget(status);                             // Добавляем ярлык в строку состояния
}
template<class T>
void MWindow::printtree(tree<T>& tree, QListWidget* list)
{
    for(auto it = tree.begin(); it != tree.end(); it++)         // Цикл по дереву
    {
        string temp;
        temp = (*it).getName();
        list->addItem(const_cast<const char*>(temp.c_str()));   // Запись названий книг в список
    }
}
void MWindow::updateList(unsigned type)
{
    if(type != 0) current_tree = type;                          // Устанавливаем новое дерево (которое мы будем выводить
    list->clear();                                              // Очищаем список
    switch(trees(current_tree)){                                // Печатаем дерево
    case SC  : printtree(tree_scb , list); break;
    case ART : printtree(tree_artb, list); break;
    case NEWS: printtree(tree_news, list); break;
    case MAG : printtree(tree_mag , list); break;
    }
}
void MWindow::saveInFile()
{
    setStatusBar(" Save in file");
    BFile<ARTBooks> file1 ("DataArtBooks.bin",   std::ios::out | std::ios::trunc); // Открываем поток
    if(file1.isOpened())                                                           // если он открылся
    for(auto it = tree_artb.begin(); it != tree_artb.end(); it++)                  // записываем
        file1.write(*it);

    BFile<SCBooks> file2 ("DataSciBooks.bin",    std::ios::out | std::ios::trunc);
    if(file2.isOpened())
    for(auto it = tree_scb.begin(); it != tree_scb.end(); it++)
        file2.write(*it);

    BFile<Newspapers> file3 ("DataNewspapers.bin", std::ios::out | std::ios::trunc);
    if(file3.isOpened())
    for(auto it = tree_news.begin(); it != tree_news.end(); it++)
        file3.write(*it);

    BFile<Magazines> file4 ("DataMagazines.bin", std::ios::out | std::ios::trunc);
    if(file4.isOpened())
    for(auto it = tree_mag.begin(); it != tree_mag.end(); it++)
        file4.write(*it);
    setStatusBar(" Saved in file");
}
void MWindow::loadFromFile()
{
    BFile<ARTBooks> file1 ("DataArtBooks.bin",   std::ios::in | std::ios::app);  // Открываем поток
    if(file1.isOpened())                                                         // если он открылся
    {
        ARTBooks t;
        while(true){                                                             // Читаем
            file1.read(t);
            if(file1.end())break;
            tree_artb.add(t);
        }
    }


    BFile<SCBooks> file2 ("DataSciBooks.bin",    std::ios::in | std::ios::app);
    if(file2.isOpened())
    {
        SCBooks t2;
        while(true){
            file2.read(t2);
            if(file2.end())break;
            tree_scb.add(t2);
        }
    }

    BFile<Newspapers> file3 ("DataNewspapers.bin", std::ios::in | std::ios::app);
    if(file3.isOpened())
    {
        Newspapers t3;
        while(true){
            file3.read(t3);
            if(file3.end())break;
            tree_news.add(t3);
        }
    }

    BFile<Magazines> file4 ("DataMagazines.bin", std::ios::in | std::ios::app);
    if(file4.isOpened())
    {
        Magazines t4;
        while(true){
            file4.read(t4);
            if(file4.end())break;
            tree_mag.add(t4);
        }
    }
}
void MWindow::setStatusBar(std::string str)
{
    status->clear();
    status->setText(QString::fromUtf8(str.c_str()));
}
