#include<QApplication>
#include<QWidget>
#include<QLabel>
#include<QDial>
#include<QLayout>
#include"MyLCD.h"
#include "ButtonCount.h"
#include "myWindow.h"


int main(int argc, char* argv[])
{
  QApplication app(argc,argv);
  myWindow window;
  ButtonCount* bc=new ButtonCount("Appuyez!",&window);
  MyLCD* lcd=new MyLCD(2,NULL);
  QLabel * message=new QLabel("Nombre de clics:",&window);

  QVBoxLayout* layout=new QVBoxLayout();
  layout->addWidget(message);
  layout->addWidget(lcd);
  layout->addWidget(bc);

  QObject::connect(bc, SIGNAL(valueChanged(int)),lcd, SLOT(display(int)));

  window.setLayout(layout);
  window.show();

  return app.exec();
}
