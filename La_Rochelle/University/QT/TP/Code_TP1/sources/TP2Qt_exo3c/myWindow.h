#ifndef MYWINDOW_H
#define MYWINDOW_H

#include<QWidget>
#include<QMessageBox>

class myWindow : public QWidget{
public:
    myWindow();
    ~myWindow();
    void resizeEvent ( QResizeEvent *);
};
#endif // MYWINDOW_H
