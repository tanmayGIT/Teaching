#include <QApplication>

#include "myBox.h"
#include "myMainWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	myMainWindow *w = new myMainWindow();
	w->show();
	return a.exec();
};
