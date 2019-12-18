#include "myWindow.h"


    myWindow::myWindow()
    {
              setWindowTitle("QWidget Resize Event");
                 };
    myWindow::~myWindow(){};

    void myWindow::resizeEvent ( QResizeEvent * event )
    {

      QMessageBox* msg = new QMessageBox(this);
      msg->setText("Mainwindow has been resized!");
      msg->show();

    };



