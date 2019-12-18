#include <QtGui>
#include<QApplication>

#include "afficht.h"
#include "mymainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myMainWindow mmw;
    mmw.show();

    return a.exec();
}
