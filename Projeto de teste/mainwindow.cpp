#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/ftd.tif","TIF");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/coins.png","PNG");

    ImageProcessing::GrayImage<int> grayimg = ImageProcessing::QImage2GrayImage<int>(img);
//    LinAlg::Matrix<bool>imgBw = (grayimg >= 100);
//    ImageProcessing::imShow(grayimg,ui->label);
//    imgBw = ImageProcessing::Dilatation<bool>(imgBw);
//    LinAlg::Matrix<LinAlg::Matrix<unsigned> > n = ImageProcessing::bound<unsigned>(imgBw);
//    ImageProcessing::imShow(n(1,2)*20,ui->label_2);
//    std::cout << n(1,1) << std::endl;

    LinAlg::Matrix<int> test = ImageProcessing::ft2d<int>(grayimg.getGray(),5);
    ImageProcessing::imShow(test,ui->label_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

