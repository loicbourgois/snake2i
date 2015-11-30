#include "main-window.h"
#include <QApplication>
#include "util.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Util::inite();
    MainWindow w;
    w.show();
    return a.exec();
}
