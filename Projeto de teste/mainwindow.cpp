#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/eight.tif","TIF");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/test2.tif","TIF");

    ImageProcessing::GrayImage<int> grayimg = ImageProcessing::QImage2GrayImage<int>(img);
    ImageProcessing::imShow(grayimg,ui->label);

    LinAlg::Matrix<bool>imgBw = (grayimg <= 180);
    unsigned n = ImageProcessing::bound<unsigned>(imgBw);
    std::cout << n << std::endl;
    ImageProcessing::imShow(imgBw,ui->label_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

