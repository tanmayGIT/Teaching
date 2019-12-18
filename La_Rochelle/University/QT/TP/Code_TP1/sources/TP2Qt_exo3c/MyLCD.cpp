#include<QApplication>
#include "MyLCD.h"

MyLCD::MyLCD( int value=0, QWidget * parent = 0): QLCDNumber(value,parent)
{
    printf("Constructeur de MyLCD \n");
connect(this,SIGNAL(reset(int)),this,SLOT(display(int)));
}

void MyLCD::mousePressEvent(QMouseEvent *event)
{
printf("MyLCD pressé! \n");
QApplication::beep();

emit reset(0);
}




