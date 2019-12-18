#ifndef MYHISTO_H
#define MYHISTO_H

#include <QVector>
#include <QPoint>
#include <QLabel>

class myHisto : public QLabel
{
    Q_OBJECT

public:
    myHisto();  // constructeur
    ~myHisto(); // destructeur
    void clear();
    void draw(); // methode de dessin

public slots:
        void setScale(int);
        void increasePan();
        void decreasePan();
        void setData(QVector<QPoint> *data);

/** surchage de la m�thode de la classe QLabel **/
protected:
    /** methodes pour le glisser-deposer - fin du TP **/
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    QVector<QPoint> *m_data;
    int m_pan;
    float m_scale;
    QPixmap *m_pixmap; // pointeur sur la zone de dessin

};

#endif // MYHISTO_H
