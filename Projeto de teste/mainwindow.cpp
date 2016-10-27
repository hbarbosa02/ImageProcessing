#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/point.tif","TIF");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/PlacaRuido.tif","TIF");
//    ImageProcessing::RGBImage<int> rgbimg = ImageConversion::QImage2RGBImage<int>(img);

    ImageProcessing::GrayImage<int> grayimg = ImageConversion::QImage2GrayImage<int>(img);
    ImageProcessing::GrayImage<int> grayimg2 = ImageConversion::QImage2GrayImage<int>(img2);
    ImageProcessing::GrayImage<int> aux = grayimg + 50;

    ImagePreview::imShow<int>(ImageProcessing::MediaFilter<int>(grayimg2,3),ui->label);
    ImagePreview::imShow<int>(ImageProcessing::MedianFilter<int>(grayimg2,5),ui->label_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

