#include <QtGui>
#include "ButtonCount.h"
ButtonCount::ButtonCount(const QString & text, QWidget * parent) : QPushButton(text,parent)
{
m_Count = 0;
connect(this, SIGNAL(clicked()), this, SLOT(Increment()));
}
void ButtonCount::Increment()
{
m_Count++;
// la ligne suivante assure un feedback sonore
QApplication::beep();
// emission du signal
emit(valueChanged(m_Count));
} 
