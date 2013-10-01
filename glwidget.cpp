#include <QtGui>
#include <math.h>

#include "glwidget.h"
#include "mainwindow.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    fig=0;
    xRot=-45; yRot=0; zRot=-45; zTra=0; nSca=1;
}

void GLWidget::initializeGL(){


   glClearColor(0,0,0,1);/*цвет области рисования */
   GLfloat light_col[] = {1,1,1};
   qglClearColor(Qt::white);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
   glEnable(GL_CULL_FACE);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_col);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_COLOR_MATERIAL);
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);


}
void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(nSca, nSca, nSca);
    glTranslatef(0.0f, zTra, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot, 0.0f, 0.0f, 1.0f);
    drawAxis();

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
    }
}
void GLWidget::resizeGL(int nWidth, int nHeight)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;

   if (nWidth>=nHeight)
      glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
   else
      glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);

   glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}


void GLWidget::setFigure(int input)
{
    fig = input;

}

void GLWidget::mousePressEvent(QMouseEvent* pe)
{
   ptrMousePosition = pe->pos();
}

void GLWidget::mouseReleaseEvent(QMouseEvent* pe)
{

}

void GLWidget::mouseMoveEvent(QMouseEvent* pe)
{
   xRot += 180/nSca*(GLfloat)(pe->y()-ptrMousePosition.y())/height();
   zRot += 180/nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width();

   ptrMousePosition = pe->pos();

   updateGL();
}

void GLWidget::drawAxis()
{
   glLineWidth(3.0f);

   glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
   glBegin(GL_LINES);
      glVertex3d( 1.0f,  0.0f,  0.0f);
      glVertex3d(-1.0f,  0.0f,  0.0f);
   glEnd();

   QColor halfGreen(0, 128, 0, 255);
   qglColor(halfGreen);
   glBegin(GL_LINES);
      glVertex3d( 0.0f,  1.0f,  0.0f);
      glVertex3d( 0.0f, -1.0f,  0.0f);

      glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
      glVertex3d( 0.0f,  0.0f,  1.0f);
      glVertex3d( 0.0f,  0.0f, -1.0f);
   glEnd();
}

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
    glColor3f(1.0, 0.0, 1.0);
    glVertex3d(-0.05,-0.05,0);
    glVertex3d(+0.05,-0.05,0);
    glVertex3d(+0.05,+0.05,0);

    glEnd();
}

void GLWidget::drawLineLoop()
{
    glBegin(GL_LINE_LOOP);//рисует замкнтые кривые линии
    glColor3f(1.0,0.5f,0.0f);
    glVertex3d(-0.35,-0.35,0);
    glVertex3d(+0.35,-0.35,0);
    glVertex3d(+0.35,+0.35,0);


    glEnd();
}

void GLWidget::drawTr()
{

//    glEnable(GL_ALPHA_TEST);
//    glBegin(GL_TRIANGLES);//сует треугольник
//    glColor3f(0.35,0.12,0.457);
//    glVertex3d(-0.35,-0.35,0);
//    glVertex3d(+0.35,-0.35,0);
//    glVertex3d(+0.35,+0.35,0);
//    glEnd();


    /*glBegin(GL_TRIANGLES);
    glColor3f(0.5f,0.0f,0.0f);                      // Красный
    glVertex3f( 0.0f, 0.5f, 0.0f);                  // Верх треугольника (Передняя)
    glColor3f(0.0f,0.5f,0.0f);                      // Зеленный
    glVertex3f(-0.5f,-0.5f, 0.5f);                  // Левая точка
    glColor3f(0.0f,0.0f,0.5f);                      // Синий
    glVertex3f( 0.5f,-0.50f, 0.5f);                  // Правая точка
    glColor3f(0.5f,0.0f,0.0f);                      // Красная
    glVertex3f( 0.0f,0.5f, 0.0f);                  // Верх треугольника (Правая)
    glColor3f(0.0f,0.0f,0.5f);                      // Синия
    glVertex3f( 0.5f,-0.5f, 0.5f);                  // Лево треугольника (Правая)
    glColor3f(0.0f,0.5f,0.0f);                      // Зеленная
    glVertex3f( 0.5f,-0.5f, -0.5f);                 // Право треугольника (Правая)
    glColor3f(0.5f,0.0f,0.0f);                      // Красный
    glVertex3f( 0.0f, 0.5f, 0.0f);                  // Низ треугольника (Сзади)
    glColor3f(0.0f,0.5f,0.0f);                      // Зеленный
    glVertex3f( 0.5f,-0.5f, -0.5f);                 // Лево треугольника (Сзади)
    glColor3f(0.0f,0.0f,0.5f);                      // Синий
    glVertex3f(-0.5f,-0.5f, -0.5f);                 // Право треугольника (Сзади)
    glColor3f(0.5f,0.0f,0.0f);                      // Красный
    glVertex3f( 0.0f, 0.5f, 0.0f);                  // Верх треугольника (Лево)
    glColor3f(0.0f,0.0f,0.5f);                      // Синий
    glVertex3f(-0.5f,-0.5f,-0.5f);                  // Лево треугольника (Лево)
    glColor3f(0.0f,0.5f,0.0f);                      // Зеленный
    glVertex3f(-0.5f,-0.5f, 0.5f);                  // Право треугольника (Лево)
    glEnd();*/


    glBegin(GL_QUADS);                      // Рисуем куб

    glColor3f(1.0f,0.0f,0.0f);              // Красный
    //glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_LESS, 0.7f);// говорит о том, что отрисуются все пиксели, чья альфа больше чем 0.5.
    glColor4f(1.0, 0.5, 1.0, 1.0);
    glVertex3f( 0.5f, 0.5f, 0.5f);          // Верх право квадрата (Перед)
    glVertex3f(-0.5f, 0.5f, 0.5f);          // Верх лево
    glVertex3f(-0.5f,-0.5f, 0.5f);          // Низ лево
    glVertex3f( 0.5f,-0.5f, 0.5f);          // Низ право
    glDisable(GL_ALPHA_TEST);
   //glDisable(GL_BLEND);
    glColor3f(1.0f,1.0f,0.0f);              // Желтый


    glVertex3f(-0.5f, 0.5f,-0.5f);          // Низ лево

     glVertex3f( 0.5f,-0.5f,-0.5f);          // Верх право квадрата (Зад)

    glVertex3f( 0.5f, 0.5f,-0.5f);          // Низ право
     glVertex3f(-0.5f,-0.5f,-0.5f);          // Верх лево

    glEnd();                                // Закончили квадраты


}

void GLWidget::drawTrStrip()
{
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glAlphaFunc(GL_ALWAYS, 0.5);
    glColor4f(1.0, 1.0, 1.0, 1.0);

    glBegin(GL_TRIANGLE_STRIP);//рисуем много связанных треугольников
    glColor3f(0.6,0.1,0.5);
    glVertex3f( 0.5f, 0.5f, 0.0f ); //vertex 4
    glVertex3f( 0.0f, 0.5f, 0.0f ); //vertex 2
    glVertex3f( 0.5f, 0.0f, 0.0f ); //vertex 3
    glVertex3f( 0.0f, 0.0f, 0.0f ); //vertex 1

    glEnd();
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_BLEND);

    glBegin(GL_POLYGON);
      glColor3f(0.7,0.05,0.1);
      glVertex3f(-0.2f,0.5f,-0.5f);
      glVertex3f(-0.5f,0.2f,-0.5f);
      glVertex3f(-0.5f,-0.2f,-0.5f);
      glVertex3f(-0.2f,-0.5f,-0.5f);
      glVertex3f(0.2f,-0.5f,-0.5f);
      glVertex3f( 0.5f,-0.2f,-0.5f);
      glVertex3f(0.5f,0.2f,  -0.5f);
      glVertex3f( 0.2f, 0.5f,-0.5f);

      glEnd();


    //glDisable(GL_ALPHA_TEST);
}


void GLWidget::drawPolygon()
{

    glBegin(GL_POLYGON);
      glColor3f(0.7,0.05,0.1);
      glVertex3f(-0.2f,0.5f,-0.5f);
      glVertex3f(-0.5f,0.2f,-0.5f);
      glVertex3f(-0.5f,-0.2f,-0.5f);
      glVertex3f(-0.2f,-0.5f,-0.5f);
      glVertex3f(0.2f,-0.5f,-0.5f);
      glVertex3f( 0.5f,-0.2f,-0.5f);
      glVertex3f(0.5f,0.2f,  -0.5f);
      glVertex3f( 0.2f, 0.5f,-0.5f);

      glEnd();

}

void GLWidget::drawQuadStrip()
{
    glBegin(GL_QUAD_STRIP);
     glColor3f(0.46,0.21,0.15);
    glVertex3f( 0.5f, 0.5f, 0.0f ); //vertex 4
    glVertex3f( 0.0f, 0.5f, 0.0f ); //vertex 2
    glVertex3f( 0.5f, 0.0f, 0.0f ); //vertex 3
    glVertex3f( 0.0f, 0.0f, 0.0f ); //vertex 1

    glVertex3f( 0.5f, 0.5f, 0.0f ); //vertex 2
    glVertex3f( 0.5f, 0.0f, 0.0f ); //vertex 3
    glVertex3f( 0.8f, 0.8f, 0.0f ); //vertex 1
    glVertex3f( 1.0f, 0.5f, 0.0f ); //vertex 1

    glEnd();
}

void GLWidget::drawQuad()
{
    glBegin(GL_QUADS);
     glColor3f(0.46,0.0,0.95);
    glVertex3d(+0.25,-0.55,0);//1
    glVertex3d(+0.35,-0.35,0);//2
    glVertex3d(+0.35,+0.35,0);//3
    glVertex3d(-0.35,-0.35,0);//4




    glEnd();
}

void GLWidget::drawTrFan()
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f( 0.5f, 0.5f, 0.0f ); //vertex 4
    glVertex3f( 0.0f, 0.5f, 0.0f ); //vertex 2
    glVertex3f( 0.5f, 0.0f, 0.0f ); //vertex 3

    glVertex3f( 0.5f, 0.5f, 0.0f ); //vertex 2
    glVertex3f( 0.5f, 0.0f, 0.0f ); //vertex 3
    glVertex3f( 0.8f, 0.8f, 0.0f ); //vertex 1


    glEnd();
}
