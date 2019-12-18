#ifndef BUTTONCOUNT_H
#define BUTTONCOUNT_H
#include <QObject>
#include <QPushButton>
class ButtonCount : public QPushButton
{
Q_OBJECT
public:
ButtonCount( const QString & text, QWidget *parent = 0 );
protected:
int m_Count;
signals:
void valueChanged(int);
public slots:
void Increment(void);
};
#endif
