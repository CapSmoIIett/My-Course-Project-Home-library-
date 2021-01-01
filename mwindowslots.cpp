#include "mwindow.h"

void MWindow::addReading()
{
    AddBWindow* window = new AddBWindow(tree_artb, tree_scb, tree_news, tree_mag, actionStack);      // Создаем окно
    connect(window->bOk, &QPushButton::clicked, this, &MWindow::updateListSlot);        // обновляем список при закрытии окна
    connect(window, &QDialog::rejected, this, &MWindow::setStatusDefault);
    setStatusBar("Add Book");
    window->show();
}
void MWindow::WatchArtBook()
{
    WindowAB* window = new WindowAB(*tree_artb[list->currentRow()]);                    // Создаем окно
    connect(window->bOk, &QPushButton::clicked, this, &MWindow::updateListSlot);        // обновляем список при закрытии окна
    connect(window, &QDialog::rejected, this, &MWindow::setStatusDefault);
    setStatusBar((*tree_artb[list->currentRow()]).getName());
    window->show();

}
void MWindow::WatchSciBook()
{
    WindowSB* window = new WindowSB(*tree_scb[list->currentRow()]);                     // Создаем окно
    connect(window->bOk, &QPushButton::clicked, this, &MWindow::updateListSlot);        // обновляем список при закрытии окна
    connect(window, &QDialog::rejected, this, &MWindow::setStatusDefault);
    setStatusBar((*tree_scb[list->currentRow()]).getName());
    window->show();
}
void MWindow::WatchMagazines()
{
    WindowMag* window = new WindowMag(*tree_mag[list->currentRow()]);                     // Создаем окно
    connect(window->bOk, &QPushButton::clicked, this, &MWindow::updateListSlot);        // обновляем список при закрытии окна
    connect(window, &QDialog::rejected, this, &MWindow::setStatusDefault);
    setStatusBar((*tree_mag[list->currentRow()]).getName());
    window->show();
}
void MWindow::WatchNewspapers()
{
    WindowNews* window = new WindowNews(*tree_news[list->currentRow()]);                // Создаем окно
    connect(window->bOk, &QPushButton::clicked, this, &MWindow::updateListSlot);        // обновляем список при закрытии окна
    connect(window, &QDialog::rejected, this, &MWindow::setStatusDefault);
    setStatusBar((*tree_news[list->currentRow()]).getName());
    window->show();
}
void MWindow::setABook()
{
    setStatusDefault();
    updateList(trees(ART));
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchArtBook);          // Отвязывваем вызов других менюшек
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchSciBook);          // даже текущюю (чтобы не создавалось две)
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchNewspapers);
    disconnect(list, &QListWidget::doubleClicked, this, &MWindow::WatchMagazines);
    QObject::connect(list, &QListWidget::doubleClicked, this, &MWindow::WatchArtBook);
}
void MWindow::setSBook()
{
    setStatusDefault();
    updateList(trees(SC));
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchArtBook);          // Отвязывваем вызов других менюшек
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchSciBook);          // даже текущюю (чтобы не создавалось две)
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchNewspapers);
    disconnect(list, &QListWidget::doubleClicked, this, &MWindow::WatchMagazines);
    QObject::connect(list, &QListWidget::doubleClicked, this, &MWindow::WatchSciBook );
}
void MWindow::setNewsp()
{
    setStatusDefault();
    updateList(trees(NEWS));
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchArtBook);          // Отвязывваем вызов других менюшек
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchSciBook);          // даже текущюю (чтобы не создавалось две)
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchNewspapers);
    disconnect(list, &QListWidget::doubleClicked, this, &MWindow::WatchMagazines);
    QObject::connect(list, &QListWidget::doubleClicked, this, &MWindow::WatchNewspapers);
}
void MWindow::setMagazines()
{
    setStatusDefault();
    updateList(trees(MAG));
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchArtBook);          // Отвязывваем вызов других менюшек
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchSciBook);          // даже текущюю (чтобы не создавалось две)
    disconnect(list, &QListWidget::doubleClicked,this, &MWindow::WatchNewspapers);
    disconnect(list, &QListWidget::doubleClicked, this, &MWindow::WatchMagazines);
    QObject::connect(list, &QListWidget::doubleClicked, this, &MWindow::WatchMagazines);
}
void MWindow::updateListSlot()
{
    list->clear();                                              // Очищаем список
    switch(trees(current_tree)){                                // Печатаем рабочее дерево
    case SC  : printtree(tree_scb , list); break;
    case ART : printtree(tree_artb, list); break;
    case NEWS: printtree(tree_news, list); break;
    case MAG : printtree(tree_mag , list); break;
    }
}
void MWindow::saveInFileSlot()
{
    saveInFile();
}
void MWindow::changeConditionNameAZ()
{
    tree_artb.set_condition(conditionNameAZ);               // Установка для деревьев нового условия
    tree_news.set_condition(conditionNameAZ);
    tree_scb.set_condition(conditionNameAZ);
    tree_mag.set_condition(conditionNameAZ);
    setStatusDefault();
    updateList();
}
void MWindow::changeConditionNameZA()
{
    tree_artb.set_condition(conditionNameZA);               // Установка для деревьев нового условия
    tree_news.set_condition(conditionNameZA);
    tree_scb.set_condition(conditionNameZA);
    tree_mag.set_condition(conditionNameZA);
    setStatusDefault();
    updateList();
}
void MWindow::changeConditionPagesIncr()
{
    tree_artb.set_condition(conditionPagesIncr);            // Установка для деревьев нового условия
    tree_news.set_condition(conditionPagesIncr);
    tree_scb.set_condition(conditionPagesIncr);
    tree_mag.set_condition(conditionPagesIncr);
    setStatusDefault();
    updateList();
}
void MWindow::changeConditionPagesDecr()
{
    tree_artb.set_condition(conditionPagesDecr);            // Установка для деревьев нового условия
    tree_news.set_condition(conditionPagesDecr);
    tree_scb.set_condition(conditionPagesDecr);
    tree_mag.set_condition(conditionPagesDecr);
    setStatusDefault();
    updateList();
}
void MWindow::customMenuSlot(QPoint position)
{
    QMenu *menu = new QMenu(this);                          // Создание контекстного меню
    QAction *show = menu->addAction("&show");
    QAction *del  = menu->addAction("&delete");
    switch(trees(current_tree)){                            // Печатаем рабочее дерево
    case SC  :  connect(show, &QAction::triggered, this, &MWindow::WatchSciBook); break;
    case ART :  connect(show, &QAction::triggered, this, &MWindow::WatchArtBook); break;
    case NEWS:  connect(show, &QAction::triggered, this, &MWindow::WatchNewspapers); break;
    case MAG :  connect(show, &QAction::triggered, this, &MWindow::WatchMagazines); break;
    }
    connect(del,&QAction::triggered, this, &MWindow::deleteElementList);
    menu->exec(QCursor::pos());                             // вывод на экран меню
}
void MWindow::deleteElementList()
{
    switch(trees(current_tree)){                                // Выбираем рабочее дерево и удаляем выбранный элемент
    case SC  :
    {
        addActionStack(actionStack, *tree_scb[list->currentRow()], &tree_scb, 0);
        tree_scb.remove(tree_scb[list->currentRow()]);  break;
    }
    case ART :
    {
        addActionStack(actionStack, *tree_artb[list->currentRow()], &tree_artb, 0);
        tree_artb.remove(tree_artb[list->currentRow()]); break;
    }
    case NEWS:
    {
        addActionStack(actionStack, *tree_news[list->currentRow()], &tree_news, 0);
        tree_news.remove(tree_news[list->currentRow()]); break;
    }
    case MAG :
    {
        addActionStack(actionStack, *tree_mag[list->currentRow()], &tree_mag, 0);
        tree_mag.remove(tree_mag[list->currentRow()]); break;
    }
    }
    updateList();
}
void MWindow::undoActionSlot()
{
    returnAction(actionStack);              // Отменяем последнее действие
    setStatusDefault();
    updateList();
}
void MWindow::searchSlot()
{
    if(search->text() == ""){               // Если строку очистить то печатается рабочее дерево
        updateList();
        return;
    }
    list->clear();
    string temp = "";
    auto it  = tree_artb.find2(ARTBooks(search->text().toUtf8().constData()));  // Поиск подходящего элемента в каждом дереве
    auto it2 = tree_scb.find2(SCBooks(search->text().toUtf8().constData()));
    auto it3 = tree_news.find2(Newspapers(search->text().toUtf8().constData()));
    auto it4 = tree_mag.find2(Magazines(search->text().toUtf8().constData()));
    if(it != tree_artb.end())
    {
        temp = (*it).getName();
        list->addItem(const_cast<const char*>(temp.c_str()));
        setStatusDefault();
    }
    if(it2 != tree_scb.end())
    {
        temp = (*it2).getName();
        list->addItem(const_cast<const char*>(temp.c_str()));
        setStatusDefault();
    }
    if(it3 != tree_news.end())
    {
        temp = (*it3).getName();
        list->addItem(const_cast<const char*>(temp.c_str()));
        setStatusDefault();
    }
    if(it4 != tree_mag.end())
    {
        temp = (*it4).getName();
        list->addItem(const_cast<const char*>(temp.c_str()));
        setStatusDefault();
    }
    if(temp == "")                                                  // Если ничего не найденно
    {
        setStatusBar(" not found ");
    }
}
void MWindow::setStatusDefault()                                    // Установка строки состояния в обычное положение
{
    status->clear();
    status->setText(QString::fromUtf8(" No file select "));
}
void MWindow::errorGet(std::string str)                             // Установка строки состояния
{
    setStatusBar(str);
}
