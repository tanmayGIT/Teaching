#include<QApplication>
#include<QWidget>
#include<QLabel>
#include<QDial>
#include<QLayout>
#include<QLCDNumber>
#include "ButtonCount.h"

int main(int argc, char* argv[])
{
  QApplication app(argc,argv);
  QWidget window;
  ButtonCount* bc=new ButtonCount("Coucou",&window);
  QLCDNumber* lcd=new QLCDNumber(2);
  QLabel * message=new QLabel("Cliquez!",&window);
  //QDial* dial=new QDial();
 
  QVBoxLayout* layout=new QVBoxLayout();
  layout->addWidget(message);
  layout->addWidget(lcd);
  layout->addWidget(bc);
  //layout->addWidget(dial);
  window.setLayout(layout);

  //QObject::connect(dial,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
  QObject::connect(bc, SIGNAL(valueChanged(int)),lcd, SLOT(display(int)));
  window.show();
  return app.exec();
}
