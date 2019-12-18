#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<X11/Xlib.h>

class XApplication: public QApplication

{

public:

    XApplication (int & argc, char **argv): QApplication (argc , argv) { }

protected:
    bool x11EventFilter (XEvent *e)

    {
        // Question1
        // qDebug() << "Event type:" << e->type;


        switch(e->type)
        {
         case ButtonPress:
            qDebug() << "MousePress Event! " << e->type;
            // Question 2:
            qDebug() << "Position du clic souris (x= " << e->xbutton.x << ",y=" << e->xbutton.y<<")";

            // Question 3:
            if(e->xbutton.state&ControlMask)
            {
                qDebug() << "Exit!";
                qApp->exit();
            }
            break;

        default:
            break;

        }
        return QApplication::x11EventFilter(e);
    }
};


int main(int argc, char *argv[])
{
    XApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
