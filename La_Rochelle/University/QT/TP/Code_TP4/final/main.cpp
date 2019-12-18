

#include <QApplication>

#include "window.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(tp4_qt);

    QApplication app(argc, argv);

    Window window;

    window.show();
    window.setWindowState(Qt::WindowMaximized);
    return app.exec();
}
