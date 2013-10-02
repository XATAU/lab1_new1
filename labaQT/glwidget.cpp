#include "glwidget.h"
#include "mainwindow.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLWidget::initializeGL()
{
    glClearColor(0,0,0,1);//цвет области рисования

};
void GLWidget::setFigure(int input)
{
    fig = input;

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    switch (fig)
    {
        case 0:
        break;
        case 1:
        drawPolygon();
        break;
        case 2:
        drawQuadStrip();
        break;
        case 3:
        drawQuad();
        break;
        case 4:
        drawTrFan();
        break;
        case 5:
        drawTrStrip();
        break;
        case 6:
        drawTr();
        break;
        case 7:
        drawLineLoop();
        break;
        case 8:
        drawLineStrip();
        break;
        case 9:
        drawLine();
        break;
        case 10:
        drawPoint();
        break;
        case 11:
        Sci();

    }

};


void GLWidget::resizeGL(int w,int h)
{



};
void GLWidget::drawPoint()
{
    glBegin(GL_POINTS);//рисуем точку
    glColor3f(1,0,0);
    glVertex3d(-0.05,-0.05,0);
    glEnd();
}

void GLWidget::drawLine()
{
    glBegin(GL_LINES);//рисуем прямую
    glColor3f(1,1,0);
    glVertex3d(-0.05,-0.05,0);
    glVertex3d(+0.05,-0.05,0);

    glEnd();
}

void GLWidget::drawLineStrip()
{
    glBegin(GL_LINE_STRIP);//рисуем последовательные прямые
    glVertex3d(-0.05,-0.05,0);
    glVertex3d(+0.05,-0.05,0);
    glVertex3d(+0.05,+0.05,0);

    glEnd();
}

void GLWidget::drawLineLoop()
{
    glBegin(GL_LINE_LOOP);//рисует замкнтые кривые линии
    glVertex3d(-0.35,-0.35,0);
    glVertex3d(+0.35,+0.35,0);
    glVertex3d(+0.35,-0.35,0);

    glEnd();
}

void GLWidget::drawTr()
{
    glBegin(GL_TRIANGLES);//сует треугольник
    glVertex3d(-0.35,-0.35,0);
    glVertex3d(+0.35,+0.35,0);
    glVertex3d(+0.35,-0.35,0);

    glEnd();
}

void GLWidget::drawTrStrip()
{
    glBegin(GL_TRIANGLE_STRIP);//рисуем много связанных треугольников
    glColor3f(1,0.2,0);
    glVertex3d(-0.35,-0.35,0);
    glVertex3d(+0.35,+0.35,0);
    glVertex3d(+0.05,-0.35,0);

    glColor3f(1,1,0);
    glVertex3d(+0.55,-0.55,0);
    glEnd();
}


void GLWidget::drawPolygon()
{
    glBegin(GL_POLYGON);
    glVertex3d(-0.35,-0.35,0);
    glVertex3d(+0.35,+0.35,0);
    glVertex3d(+0.85,-0.35,0);
    glVertex3d(+0.55,-0.55,0);
    glVertex3d(+0.55,+0.55,0);

    glEnd();
}

void GLWidget::drawQuadStrip()
{
    glBegin(GL_QUAD_STRIP);
    glVertex3d(-0.35,-0.55,0);
    glVertex3d(+0.35,+0.55,0);
    glVertex3d(+0.35,-0.55,0);
    glVertex3d(+0.55,-0.55,0);
    glVertex3d(+0.55,+0.55,0);

    glEnd();
}

void GLWidget::drawQuad()
{
    glBegin(GL_QUADS);
    glVertex3d(-0.35,-0.35,0);
    glVertex3d(+0.35,+0.35,0);
    glVertex3d(+0.35,-0.35,0);
    glVertex3d(+0.55,-0.55,0);

    glEnd();
}

void GLWidget::drawTrFan()
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(-0.35,-0.35,0);
    glVertex3d(+0.35,+0.35,0);
    glVertex3d(+0.35,-0.35,0);

    glVertex3d(+0.55,-0.55,0);

    glEnd();
}
void GLWidget::Sci()
{
    glScissor(0,0,600,600);//отсекаю квадрат 600x600 от центра координат
    glEnable(GL_SCISSOR_TEST);//разрешаю отсечение
    //тут по идеи вызываю функцию рисования фигуры любой
    glDisable(GL_SCISSOR_TEST);//запрещаю рисовать


}
