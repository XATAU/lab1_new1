#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStatusBar"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_11_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованна точка"));
    ui->widget->setFigure(10);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_10_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованна прямая"));
ui->widget->setFigure(9);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_9_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованны последовательные прямые"));
    ui->widget->setFigure(8);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_8_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованны замкнтые кривые линии"));
   ui->widget->setFigure(7);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_7_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованн треугольник"));
 ui->widget->setFigure(6);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_6_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованны треугольники с общей вершиной"));
   ui->widget->setFigure(5);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_5_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованнв треугольники, имеющие общюу грани и одну общую вершину"));
    ui->widget->setFigure(4);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_4_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованн  четырехугольник"));
    ui->widget->setFigure(3);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_3_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ui->widget->setFigure(2);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_2_clicked()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    statusBar()->showMessage(tr("Нарисованн многоугольник"));
    ui->widget->setFigure(1);
     ui->widget->updateGL();
}

void MainWindow::on_pushButton_12_clicked()
{
    statusBar()->showMessage(tr("Отсечение"));
    ui->widget->setFigure(11);
}
