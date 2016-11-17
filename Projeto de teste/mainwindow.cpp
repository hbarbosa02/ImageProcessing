#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/eight.tif","TIF");
    img2.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/test1.tif","TIF");

    ImageProcessing::GrayImage<int> grayimg = ImageProcessing::QImage2GrayImage<int>(img2);

    LinAlg::Matrix<bool>imgBw = (grayimg >= 180);
    ImageProcessing::imShow(imgBw,ui->label);

    imgBw = ImageProcessing::Dilatation<bool>(imgBw);

    LinAlg::Matrix<LinAlg::Matrix<unsigned>> n = ImageProcessing::bound<unsigned>(imgBw);
    std::cout << n(1,1) << std::endl;

    ImageProcessing::imShow(n(1,2)*20,ui->label_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

