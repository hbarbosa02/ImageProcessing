#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/Flor.bmp","BMP");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/Flor.bmp","BMP");

    ImageProcessing::RGBImage<int> rgbimg = ImageProcessing::QImage2RGBImage<int>(img);

    ImageProcessing::GrayImage<int> grayimg = ImageProcessing::QImage2GrayImage<int>(img);
    ImageProcessing::GrayImage<int> grayimg2 = ImageProcessing::QImage2GrayImage<int>(img2);
    ImageProcessing::RGBImage<int> aux;
    aux = ImageProcessing::ColorInversion<int>(rgbimg);

    ImageProcessing::imShow<int>(rgbimg,ui->label);
    ImageProcessing::imShow<int>(aux,ui->label_2);

    ImageProcessing::plot<int>(ImageProcessing::Histogram<int>(grayimg),ui->widget_3);
//    ImageProcessing::bar<int>(ImageProcessing::Histogram<int>(aux),ui->widget_4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

