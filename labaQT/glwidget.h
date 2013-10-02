#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    int fig;
    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);
    void setFigure(int input);

    void drawPolygon();
    void drawQuadStrip();
    void drawQuad();
    void drawTrFan();
    void drawTrStrip();
    void drawTr();
    void drawLineLoop();
    void drawLineStrip();
    void drawLine();
    void drawPoint();
    void Sci();
};

#endif // GLWIDGET_H
