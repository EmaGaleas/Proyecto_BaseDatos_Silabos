#include "cframe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cframe w;
    w.showMaximized();
    w.show();
    return a.exec();
}
