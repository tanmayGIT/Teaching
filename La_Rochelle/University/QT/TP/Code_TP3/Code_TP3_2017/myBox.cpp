#include <QtGui>
#include "myBox.h"

 /** Constructeur **/
 myBox::myBox()
 {
     m_x = 150;  // valeur par defaut
     m_y = 150;  // valeur par defaut
     m_pixmap = new QPixmap(300, 300); // creation pixmap
     m_pixmap->fill(Qt::white);  // effacement pixmap
     setPixmap(*m_pixmap);  // association pixmap � la classe de base (QLabel)
     setAcceptDrops(true);
 }

 /** Destructeur **/
 myBox::~myBox()
 {
     delete m_pixmap;
 }

 void myBox::mousePressEvent(QMouseEvent * event)
 {
     /** char buf[50]; sprintf(buf,"Mouse loc is %d, %d",event->x(), event->y()); **/
     m_x = event->x();
     m_y = event->y();
     draw();
 }

 /** methode d'effacement **/
 void myBox::clear()
 {
     m_pixmap->fill(Qt::white);
     setPixmap(*m_pixmap);
 }

 /** Methode de dessin **/
 void myBox::draw()
 {
         m_pixmap->fill(Qt::white);
         QPainter p(m_pixmap);
         QPen pen(Qt::black,1);
         p.setPen(pen);

         p.drawRect(m_x-10,m_y-10,20, 20);

         setPixmap(*m_pixmap);
 }

 /** les methodes du "glisser-d�poser" sont pour la fin du TP **/
 /** methode apell� lors du "glisser" **/
 void myBox::dragEnterEvent(QDragEnterEvent *event)
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
 void myBox::dropEvent(QDropEvent *event)
 {
     /** le code convient pour le modele URL seulement **/
     const QMimeData *mimeData = event->mimeData();
     if ( mimeData->hasText())
     {
         QUrl u = mimeData->text();
         QString	filename = QFileInfo( u.toString() ).fileName();

         // Attention... le fichier doit �tre dans le repertoire de l'application

         // Test sur l'extension du fichier
         if(QFileInfo( u.toString() ).completeSuffix() == "box")
         {
             QFile file(filename);
             if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // ouverture en lecture et mode texte
                 return;

             QByteArray line;
             while (!file.atEnd()) // lecture ligne par ligne jusqu'a la fin du fichier
             {
                 line = file.readLine();
                 sscanf(line,"%d %d", &m_x, &m_y);
                 draw();
             }
             event->acceptProposedAction();
         }
     }
     else if ( mimeData->hasUrls())
     {
         QString filename;
         QUrl u;
         foreach ( u, mimeData->urls() )
             filename = QFileInfo( u.toString() ).fileName();

         // Attention... le fichier doit �tre dans le repertoire de l'application

         // Test sur l'extension du fichier
         if(QFileInfo( u.toString() ).completeSuffix() == "box")
         {
             QFile file(filename);
             if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // ouverture en lecture et mode texte
                 return;

             QByteArray line;
             while (!file.atEnd()) // lecture ligne par ligne jusqu'a la fin du fichier
             {
                 line = file.readLine();
                 sscanf(line,"%d %d", &m_x, &m_y);
                 draw();
             }
             event->acceptProposedAction();
         }
     }
 }

