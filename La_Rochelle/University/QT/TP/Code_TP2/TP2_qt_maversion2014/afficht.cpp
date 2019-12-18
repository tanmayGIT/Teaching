#include "afficht.h"
#include<iostream>
#include<QTimer>

AffichT::AffichT(QWidget *parent)
    : QWidget(parent)
{
   // this->m_TheDialC=new myDial();
    this->m_TheSpinBoxC=new QDoubleSpinBox();
   // this->m_TheDialF=new myDial();
    this->m_TheSpinBoxF=new QDoubleSpinBox();
    this->m_progressC=new QProgressBar();
    this->m_progressF=new QProgressBar();
    m_progressC->setOrientation(Qt::Vertical);
    m_progressF->setOrientation(Qt::Vertical);


    layout = new QGridLayout();
 //   layout->addWidget(this->m_TheDialC,1,1);
    layout->addWidget(this->m_progressC,2,1);
    layout->addWidget(this->m_TheSpinBoxC,3,1);
  //  layout->addWidget(this->m_TheDialF,1,2);
    layout->addWidget(this->m_progressF,2,2);
    layout->addWidget(this->m_TheSpinBoxF,3,2);

    this->setLayout(layout);

// connect(this->m_TheDialC,SIGNAL(valueChanged(int)),this->m_TheSpinBoxC,SLOT(setValue(int)));
// connect(this->m_TheSpinBoxC,SIGNAL(valueChanged(int)),this->m_TheDialC,SLOT(setValue(int)));
// connect(this->m_TheDialF,SIGNAL(valueChanged(int)),this->m_TheSpinBoxF,SLOT(setValue(int)));
// connect(this->m_TheSpinBoxF,SIGNAL(valueChanged(int)),this->m_TheDialF,SLOT(setValue(int)));


    connect(this->m_TheSpinBoxC,SIGNAL(valueChanged(double)),this,SLOT(SetValueC2F()));
    connect(this->m_TheSpinBoxF,SIGNAL(valueChanged(double)),this,SLOT(SetValueF2C()));
//   connect(this->m_TheDialC,SIGNAL(valueChanged(int)),this,SLOT(SetValueC2F()));
 //   connect(this->m_TheDialF,SIGNAL(valueChanged(int)),this,SLOT(SetValueF2C()));


    //Gestion du timer
    QTimer *timer = new QTimer();
    timer->start( 2000 ); // 2 seconds single-shot timer
    connect(timer, SIGNAL(timeout()),this, SLOT(Increment()));


}

AffichT::~AffichT()
{
   // delete this->m_TheDialC;
    delete this->m_TheSpinBoxC;
 //   delete this->m_TheDialF;
    delete this->m_TheSpinBoxF;
    delete this->m_progressC;
    delete this->m_progressF;

}

void AffichT::Reset()
{
    this->m_TheSpinBoxC->setValue(0);
    this->m_TheDialC->setValue(0);

    }

void AffichT::SetValueC2F()
{
    double valueC= this->m_TheSpinBoxC->value();
    double tempC2F= double(valueC*(9.0/5.0)+32.0);
//printf("temperature C2F =%f",tempC2F);

this->m_TheSpinBoxF->setValue(tempC2F);
//this->m_TheSpinBoxC->setValue(valueC);

this->m_progressF->setValue(int(tempC2F));

if(valueC>10)
{  QPalette palette = QPalette(QColor(Qt::red) );

//   palette.setColor(Active,);
    this->m_progressC->setAutoFillBackground(true);
     this->m_progressC->setPalette(palette );
 }
else
{
    QPalette palette = this->palette(  );
    palette.setColor(QPalette::Active, QPalette::Background, QColor(Qt::lightGray));
       this->m_progressC->setAutoFillBackground(true);
        this->m_progressC->setPalette( palette );
   }


}

void AffichT::SetValueF2C()
{
double valueF= this->m_TheSpinBoxF->value();
    double tempF2C= double((valueF-32.0)*(5.0/9.0));
//printf("temperature F2C=%f",tempF2C);
//this->m_TheSpinBoxF->setValue(valueF);

this->m_TheSpinBoxC->setValue(tempF2C);
//this->m_TheDialC->setValue(int(tempF2C));
this->m_progressC->setValue(int(tempF2C));

}

void AffichT::Increment()
{
this->m_TheSpinBoxC->setValue(this->m_TheSpinBoxC->value()+1);
}
