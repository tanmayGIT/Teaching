#ifndef AFFICHT_H
#define AFFICHT_H

#include<QtGui>
#include"mdial.h"

#include<QSpinBox>
#include<QVBoxLayout>
#include<QProgressBar>

class AffichT : public QWidget
{
    Q_OBJECT

public:
    AffichT(QWidget *parent = 0);
    ~AffichT();
    void Reset();
private:
    myDial *m_TheDialC;
   QDoubleSpinBox *m_TheSpinBoxC;
   QProgressBar *m_progressC;
   QProgressBar *m_progressF;

    myDial *m_TheDialF;
   QDoubleSpinBox *m_TheSpinBoxF;

    QGridLayout *layout;


private slots:
    void SetValueC2F();
    void SetValueF2C();
    void Increment();
 };

#endif // AFFICHT_H
