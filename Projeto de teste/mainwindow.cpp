#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img, img2;
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/toycars1.png","PNG");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/toycars2.png","PNG");
    ImageProcessing::RGBImage<int> rgbimg = ImageConversion::QImage2RGBImage<int>(img);

    ImageProcessing::GrayImage<int> grayimg = ImageConversion::QImage2GrayImage<int>(img);
    ImageProcessing::GrayImage<int> grayimg2 = ImageConversion::QImage2GrayImage<int>(img2);
    ImageProcessing::GrayImage<int> aux ;

    aux = grayimg - grayimg2;

    ui->label->setPixmap(QPixmap::fromImage(ImageConversion::GrayImage2QImage<int>(grayimg)));
    ui->label_2->setPixmap(QPixmap::fromImage(ImageConversion::GrayImage2QImage<int>(grayimg2)));
    ui->label_3->setPixmap(QPixmap::fromImage(ImageConversion::GrayImage2QImage<int>(aux)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
