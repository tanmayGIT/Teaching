#include <QWidget>
#include <QLabel>
#include <QAction>
#include <QPushButton>
#include <QMenu>
#include <QMenubar>

#include "mymainwindow.h"

myMainWindow::myMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget *w = new QWidget;
    setCentralWidget(w);

   m_QLabel=new QLabel(tr("Fenetre d'affichage"));
   m_QLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
   m_QLabel->setAlignment(Qt::AlignCenter);

   m_clear = new QPushButton(tr("Clear"));
   m_TCelcius=new AffichT();

    vbox = new QVBoxLayout;
    vbox->addWidget(this->m_QLabel);
    vbox->addWidget(this->m_TCelcius);
    vbox->addWidget(this->m_clear);

    /** w est le widget parent, qui affiche tous les autres **/
    w->setLayout(vbox);
    this->createActions();
    this->createMenus();

}

/** destructeur **/
myMainWindow::~myMainWindow()
{
 delete m_QLabel;
 delete m_TCelcius;
 delete m_clear;
}

void myMainWindow::createActions()
{
    /** mise en relation article de menu -> slots **/
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
   connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

   saveAct = new QAction(tr("&Save..."), this);
   saveAct->setShortcut(tr("Ctrl+S"));
  connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

  exitAct = new QAction(tr("&Sortie..."), this);
  exitAct->setShortcut(tr("Ctrl+X"));
 connect(exitAct, SIGNAL(triggered()), this, SLOT(exit()));

 resetAct = new QAction(tr("&Reset..."), this);
 resetAct->setShortcut(tr("Ctrl+R"));
connect(resetAct, SIGNAL(triggered()), this, SLOT(reset()));


    /** mise en relation boutons m_clear-> slot clear() **/
    connect(m_clear, SIGNAL(clicked()), this, SLOT(clear()));

}


void myMainWindow::createMenus()
{
    fileMenu = this->menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    optionMenu = this->menuBar()->addMenu(tr("&Display"));
   optionMenu->addAction(resetAct);

}

void myMainWindow::open()
{
this->m_QLabel->setText(tr("Invoked File/Open"));
}

void myMainWindow::save()
{
this->m_QLabel->setText(tr("Invoked File/Save"));
}

void myMainWindow::clear()
{
this->m_QLabel->setText(tr("Clear button pressed"));

}

void myMainWindow::exit()
{
this->m_QLabel->setText(tr("Invoked File/Exit"));
    qApp->quit();
}

void myMainWindow::reset()
{
this->m_QLabel->setText(tr("Invoked Display/Reset to defaults"));
}
