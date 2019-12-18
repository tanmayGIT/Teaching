/****************************************************************************
**
** Copyright (C) 2005-2007 Trolltech ASA. All rights reserved.
****************************************************************************/

#include <QtGui>

#include "qslider.h"
#include "glwidget.h"
#include "window.h"
#include "ui_frame_pour_TP4.h"

Window::Window()
{

    QGridLayout *mainLayout = new QGridLayout;


            QColor clearColor;
            clearColor.setHsv(0, 255, 163);

            glWidget = new GLWidget;
            glWidget->setClearColor(clearColor);
            mainLayout->addWidget(glWidget,1,1);

            QSlider *slider1= createSlider();
            QSlider *slider2= createSlider();
            QSlider *slider3= createSlider();
            mainLayout->addWidget(slider1,2,1);
           mainLayout->addWidget(slider2,3,1);
           mainLayout->addWidget(slider3,4,1);
            QObject::connect( slider1, SIGNAL(valueChanged(int)), glWidget,SLOT(rotate_x(int)) );
            QObject::connect( slider2, SIGNAL(valueChanged(int)), glWidget,SLOT(rotate_y(int)) );
            QObject::connect( slider3, SIGNAL(valueChanged(int)), glWidget,SLOT(rotate_z(int)) );

            Ui::Frame ui;
            QFrame *my_frame = new QFrame;
            ui.setupUi(my_frame);
            mainLayout->addWidget(my_frame,5,1);
            QObject::connect(ui.spinBox_x,SIGNAL(valueChanged(int)),glWidget,SLOT(rotate_x(int)));
            QObject::connect(ui.spinBox_y,SIGNAL(valueChanged(int)),glWidget,SLOT(rotate_y(int)));
            QObject::connect(ui.spinBox_z,SIGNAL(valueChanged(int)),glWidget,SLOT(rotate_z(int)));


            setLayout(mainLayout);


   QTimer *timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(rotateOneStep()));
   QObject::connect(ui.pushButton_stop,SIGNAL(clicked()),timer,SLOT(stop()));
   QObject::connect(ui.pushButton_start,SIGNAL(clicked()),timer,SLOT(start()));
   timer->start(50);

    setWindowTitle(tr("The Dreamteam"));
}


void Window::rotateOneStep()
{

       glWidget->rotateBy(+2 * 16, +2 * 16, -1 * 16);
}

QSlider *Window::createSlider()
{
        QSlider *slider = new QSlider(Qt::Horizontal);
        slider->setRange(0, 360 );
        slider->setSingleStep(16);
        slider->setPageStep(15 );
        slider->setTickInterval(15);
        slider->setTickPosition(QSlider::TicksRight);
        return slider;
}
