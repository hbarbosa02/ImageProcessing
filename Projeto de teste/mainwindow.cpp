#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/ovo2.jpg","JPG");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/test2.tif","TIF");

    ImageProcessing::GrayImage<int> grayimg = ImageProcessing::QImage2GrayImage<int>(img);
    ImageProcessing::imShow(grayimg,ui->label);

    grayimg = ImageProcessing::GaussianFilter(grayimg,5);
    ImageProcessing::imShow<int>(grayimg,ui->label_2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

