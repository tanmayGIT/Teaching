#include<QApplication>
#include<QWidget>
#include<QLabel>
#include<QDial>
#include<QLayout>
#include<QLCDNumber>

using namespace std;


int main(int argc, char* argv[])
{
  QApplication app(argc,argv);
  QWidget window;
  QLCDNumber* lcd=new QLCDNumber(2);
  QLabel * message=new QLabel("Hello,World",&window);
  QDial* dial=new QDial();

  QVBoxLayout* layout=new QVBoxLayout();
  layout->addWidget(message);
  layout->addWidget(lcd);
  layout->addWidget(dial);
  window.setLayout(layout);

  connect(dial,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
  window.show();
  return app.exec();
}




