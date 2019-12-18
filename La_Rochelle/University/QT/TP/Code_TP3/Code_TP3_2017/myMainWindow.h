   #ifndef MYWIDGET_H
    #define MYWIDGET_H

    //#include "myBox.h"
    #include "myhisto.h"
	#include <QMainWindow>

    class QLabel;
    class QSlider;
	class QPushButton;

    class myMainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        myMainWindow();  // constructeur
		~myMainWindow(); // destructeur

    private slots:
        void open();
        void save();
		void exit();
        void reset();

	protected slots:
		void clear();

    private:
        void createActions();
        void createMenus();

        QMenu *fileMenu;
        QMenu *optionMenu;

        QAction *openAct;
        QAction *saveAct;
        QAction *exitAct;
        QAction *resetAct;

        QLabel *m_infoLabel;
        //myBox *m_myBox;
        myHisto *m_myHisto;
        QPushButton *m_panLeft;
        QSlider *m_scaleSlider;
        QPushButton *m_panRight;
        QPushButton *m_clear;
    };

    #endif
