#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include "AffichT.h"
#include <QtGUI>
#include <QWidget>
#include <QMainWindow>

class QLabel;
class QSlider;
class QPushButton;


class myMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    myMainWindow(QWidget *parent = 0);
    ~myMainWindow(); // destructeur

signals:

private slots:
    void open();
    void clear();
    void save();
    void exit();
    void reset();

private:
    QLabel *m_QLabel;
    QVBoxLayout *vbox;
    QPushButton *m_clear;
    AffichT *m_TCelcius;
    QMenu *fileMenu;
    QMenu *optionMenu;

    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;
    QAction *resetAct;
   void createActions();
    void createMenus();

};

#endif // MYMAINWINDOW_H
