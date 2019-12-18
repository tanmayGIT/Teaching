#include <QtGui>
#include "myhisto.h"

 /** Constructeur **/
 myHisto::myHisto()
 {
     m_data = new QVector<QPoint>();
     m_data->append(QPoint(10, 65));
     m_data->append(QPoint(20, 20));
     m_data->append(QPoint(30, 13));
     m_data->append(QPoint(40, 54));
     m_data->append(QPoint(50, 35));

     m_pan = 0;
     m_scale = 1.;

     m_pixmap = new QPixmap(300, 300); // creation pixmap
     m_pixmap->fill(Qt::white);  // effacement pixmap
     setPixmap(*m_pixmap);  // association pixmap � la classe de base (QLabel)
     setAcceptDrops(true);
 }

 /** Destructeur **/
 myHisto::~myHisto()
 {
     delete m_pixmap;
 }

 /** methode d'effacement **/
 void myHisto::clear()
 {
     //delete m_data;
     m_data->clear();
     m_scale = 1.;
     m_pan = 0;
     draw();
     update();
 }

 /** Methode de dessin **/
 void myHisto::draw()
 {
         m_pixmap->fill(Qt::white);
         QPainter p(m_pixmap);
         QPen pen(Qt::black,1);
         p.setPen(pen);
         p.setBrush(QBrush(Qt::red)); //fill rectangle with red



         QVector<QPoint>::iterator i;
         for (i = m_data->begin(); i != m_data->end(); ++i)
         {
             int x = (i->x()+m_pan) * m_scale ;
             int y = m_pixmap->height() - i->y()*m_scale;
             int w = 10 * m_scale;
             int h = i->y()*m_scale;
             p.drawRect(x, y, w, h);
         }


         setPixmap(*m_pixmap);
 }

 /** slots **/
 void myHisto::setScale(int val)
 {
     m_scale = val/100.;
     draw();
     update();
 }
 void myHisto::decreasePan()
 {
     m_pan += 10;
     draw();
     update();
 }
 void myHisto::increasePan()
 {
     m_pan -= 10;
     draw();
     update();
 }
 void myHisto::setData(QVector<QPoint> *data)
 {
    delete m_data;
    m_data = data;
 }

 /** les methodes du "glisser-d�poser" sont pour la fin du TP **/
 /** methode apell� lors du "glisser" **/
 void myHisto::dragEnterEvent(QDragEnterEvent *event)
 {
     // qApp->beep();  // indication acoustique
     if(event->mimeData()->hasText())
     {
         printf("The dragged data is seen as text");
         event->acceptProposedAction();
     }
     else if (event->mimeData()->hasUrls())
     {
         printf("The dragged data is seen as URLs");
         event->acceptProposedAction();
     }
 }

 /** methode du "deposer" **/
 void myHisto::dropEvent(QDropEvent *event)
 {

     /** le code convient pour le modele URL seulement **/
     const QMimeData *mimeData = event->mimeData();
     if ( mimeData->hasText())
     {
         QUrl u = mimeData->text();
         QString	filename = QFileInfo( u.toString() ).fileName();

         // Attention... le fichier doit �tre dans le repertoire de l'application

         // Test sur l'extension du fichier
         if(QFileInfo( u.toString() ).completeSuffix() == "dat")
         {
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
             setData(data);
             draw();
             event->acceptProposedAction();
         }
     }
     else if ( mimeData->hasUrls())
     {
         QString filename;
         QUrl u;
         foreach ( u, mimeData->urls() )
         {
            QString str = u.path();
            if(str != "")
                filename = str;
         }

         // Attention... le fichier doit �tre dans le repertoire de l'application

         // Test sur l'extension du fichier
         if(QFileInfo( u.toString() ).completeSuffix() == "dat")
         {
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
             setData(data);
             draw();
             event->acceptProposedAction();
         }
     }
 }

