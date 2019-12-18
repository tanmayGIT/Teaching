#include<QPushButton>
#include<QAction>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QMenuBar>
#include <QSlider>
#include <QFileDialog>
#include <QTextStream>

//#include "myBox.h"
#include "myMainWindow.h"

    /** constructeur **/
    myMainWindow::myMainWindow()
    {
        QWidget *w = new QWidget;
        setCentralWidget(w);

        /** creation des wigets **/
        /** zone d'affichage, peut servir pour message de debug **/
        m_infoLabel = new QLabel(tr("Zone d'affichage, peut toujours servir"));
        m_infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        m_infoLabel->setAlignment(Qt::AlignCenter);

        /** mon widget **/
        //m_myBox = new myBox();
        m_myHisto = new myHisto();

        m_panLeft = new QPushButton("<<");
        m_panLeft->setMinimumWidth(this->minimumWidth()/10.);
        QObject::connect(m_panLeft, SIGNAL(clicked(bool)), m_myHisto, SLOT(decreasePan()));
        m_scaleSlider = new QSlider();
        m_scaleSlider->setMinimumWidth(this->minimumWidth()*8./10);
        m_scaleSlider->setOrientation(Qt::Horizontal);
        m_scaleSlider->setValue(100);
        m_scaleSlider->setRange(0,1000);
        m_scaleSlider->setTickInterval(1);
        QObject::connect(m_scaleSlider, SIGNAL(valueChanged(int)), m_myHisto, SLOT(setScale(int)));
        m_panRight = new QPushButton(">>");
        m_panRight->setMinimumWidth(this->minimumWidth()/10.);
        QObject::connect(m_panRight, SIGNAL(clicked(bool)), m_myHisto, SLOT(increasePan()));

        QHBoxLayout *hbox = new QHBoxLayout;
        hbox->addWidget(m_panLeft);
        hbox->addWidget(m_scaleSlider);
        hbox->addWidget(m_panRight);

        /** 2 boutons poussoir **/
        m_clear = new QPushButton(tr("Clear"));

        /** cr�ation d'un objet conteneur **/
        /** voir aussi la classe QGridLayout **/
        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->setMargin(5);
        vbox->addWidget(m_infoLabel);
        //vbox->addWidget(m_myBox);
        vbox->addWidget(m_myHisto);
        vbox->addLayout(hbox);
        vbox->addWidget(m_clear);

        /** w est le widget parent, qui affiche tous les autres **/
        w->setLayout(vbox);

        /** association slot -> methodes, voir methode **/
        createActions();
        /** creation barre de menu, voir methode **/
        createMenus();

        setWindowTitle(tr("Application de base: trace de boite"));
        setMinimumSize(310, 450);
        resize(310, 450);
    }

    /** destructeur **/
    myMainWindow::~myMainWindow()
    {
        delete m_infoLabel;
        //delete m_myBox;
        delete m_myHisto;
        delete m_clear;
    }

    void myMainWindow::open()
    {
        m_infoLabel->setText(tr("Invoked <b>File|Open</b>"));
       // QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"), QDir::currentPath(), tr("Histogrammes (*.dat)"));
        QString filename = QFileDialog::getOpenFileName(this,
            tr("Open File"), "./",
        tr("all datas(*.dat *.box);;Box Coordinates(*.box);;Boxes Coordinates(*.dat)")) ;


        QFile file(filename);
        QVector<QPoint> *data = new QVector<QPoint>();
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
           QTextStream in(&file);
           while (!in.atEnd())
           {
              QString line = in.readLine();
              QStringList values = line.split(" ");
              data->append(QPoint(values[0].toInt(), values[1].toInt()));
           }
           file.close();
        }
        m_myHisto->setData(data);
        //m_myBox->draw();
        m_myHisto->draw();
    }

    void myMainWindow::save()
    {
        m_infoLabel->setText(tr("Invoked <b>File|Save</b>"));
    }

    void myMainWindow::exit()
    {
                m_infoLabel->setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b>"));
        ::exit(0);
    }

    void myMainWindow::reset()
    {
        m_infoLabel->setText(tr("Invoked <b>Display|Reset to defaults</b>"));
    }

    void myMainWindow::clear()
    {
        m_infoLabel->setText(tr("Button <b>clear</b> pressed"));
        //m_myBox->clear();
        m_myHisto->clear();
    }

    void myMainWindow::createActions()
    {
        /** mise en relation article de menu -> slots **/
        openAct = new QAction(tr("&Open..."), this);
        openAct->setShortcut(tr("Ctrl+O"));
        connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

        saveAct = new QAction(tr("&Save"), this);
        saveAct->setShortcut(tr("Ctrl+S"));
        connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

        exitAct = new QAction(tr("E&xit"), this);
        exitAct->setShortcut(tr("Ctrl+Q"));
        connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

        resetAct = new QAction(tr("Reset to defaults..."), this);
        connect(resetAct, SIGNAL(triggered()), this, SLOT(reset()));

        /** mise en relation boutons -> slots **/
        connect(m_clear, SIGNAL(clicked()), this, SLOT(clear()));
    }

    void myMainWindow::createMenus()
    {
        fileMenu = menuBar()->addMenu(tr("&File"));
        fileMenu->addAction(openAct);
        fileMenu->addAction(saveAct);
        fileMenu->addSeparator();
        fileMenu->addAction(exitAct);

        optionMenu = menuBar()->addMenu(tr("&Display"));
        optionMenu->addAction(resetAct);
    }
