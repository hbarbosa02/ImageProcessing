#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/Flor.bmp","BMP");

//    this->rgbimg = ImageProcessing::RGBImage(img);

    rgbimg = new ImageProcessing::RGBImage(img);
}

MainWindow::~MainWindow()
{
    delete ui;
}

