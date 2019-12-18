

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QSlider;
class GLWidget;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private slots:
    void rotateOneStep();

private:
        QSlider *createSlider();
        GLWidget *glWidget;

};

#endif
