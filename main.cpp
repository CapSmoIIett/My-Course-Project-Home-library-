#include "mwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MWindow w;                          // Создание главного окна
    w.show();                           // Вызов    главного окна
    return app.exec();
}
