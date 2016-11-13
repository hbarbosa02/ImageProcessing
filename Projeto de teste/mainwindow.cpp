#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/ovo2.jpg","JPG");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/test2.tif","TIF");

//    ImageProcessing::RGBImage<double> rgbimg = ImageProcessing::QImage2RGBImage<double>(img);
//    ImageProcessing::GrayImage<int> grayimg2 = ImageProcessing::QImage2GrayImage<int>(img2);
//    ImageProcessing::GrayImage<int> aux;

    ImageProcessing::GrayImage<int> grayimg = ImageProcessing::QImage2GrayImage<int>(img);
    LinAlg::Matrix<bool> aux = ImageProcessing::im2bw(grayimg,190);

    ImageProcessing::imShow(aux,ui->label);
    ImageProcessing::imShow<int>(grayimg,ui->label_2);

    int n = ImageProcessing::bound<bool>(aux);
    std::cout << n << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

