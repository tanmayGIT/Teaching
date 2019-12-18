#ifndef MYLCD_H
#define MYLCD_H

#endif // MYLCD_H
#include <QLCDNumber>


class MyLCD : public QLCDNumber
{
Q_OBJECT

public:
MyLCD( int, QWidget *);

public slots:
void mousePressEvent(QMouseEvent *);

signals:
void reset(int );

};

