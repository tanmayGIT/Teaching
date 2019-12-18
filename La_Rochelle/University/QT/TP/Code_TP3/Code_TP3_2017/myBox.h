#ifndef MYBOX_H
 #define MYBOX_H

 #include <QLabel>

 class myBox : public QLabel
 {
     Q_OBJECT

 public:
     myBox();  // constructeur
     ~myBox(); // destructeur
     void clear();
     void draw(); // methode de dessin

 /** surchage de la m�thode de la classe QLabel **/
 protected:
     virtual void mousePressEvent(QMouseEvent * event);

     /** methodes pour le glisser-deposer - fin du TP **/
     void dragEnterEvent(QDragEnterEvent *event);
     void dropEvent(QDropEvent *event);

 private:
     int m_x, m_y; // position du centre du rectangle
     QPixmap *m_pixmap; // pointeur sur la zone de dessin

 };

 #endif
