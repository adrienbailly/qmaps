#include <QtGui/QApplication>
#include "qmaps.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Maps w;
    w.show();
    
    return a.exec();
}
