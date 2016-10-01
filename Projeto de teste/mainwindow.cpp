#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QImage"
#include "TesteClasses/rgbimage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage img;
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/Flor.bmp","BMP");

    ImageProcessing::RGBImage rgbImage(img);

    QImage rgbImgToQImg = ImageProcessing::rgbImg2QImage(rgbImage);
    QImage imgGray = rgbImage.grayImage();
    QImage imgRed = rgbImage.redImage();
    QImage imgGreen = rgbImage.greenImage();
    QImage imgBlue = rgbImage.blueImage();

//    LinAlg::Matrix<int> bitMat = ImageProcessing::bitMap(rgbImage);
//    QImage bitMap = ImageProcessing::bitMap2Image(bitMat);

    ///Imagem original
    ui->label->setPixmap(QPixmap::fromImage(img));
    ///Imagem RGBImage to QImage
    ui->label_2->setPixmap(QPixmap::fromImage(rgbImgToQImg));
    ///Imagem Gray
    ui->label_3->setPixmap(QPixmap::fromImage(imgGray));
    ///Imagem Red
    ui->label_4->setPixmap(QPixmap::fromImage(imgRed));
    ///Imagem Green
    ui->label_5->setPixmap(QPixmap::fromImage(imgGreen));
    ///Imagem Blue
    ui->label_6->setPixmap(QPixmap::fromImage(imgBlue));
}

MainWindow::~MainWindow()
{
    delete ui;
}
