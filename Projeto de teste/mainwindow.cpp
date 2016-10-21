#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img;
    img.load("F:/Unp/8ªSemestre/Visão Computacional/Nova pasta/Flor.bmp","BMP");
    ImageProcessing::RGBImage<int> rgbimg = ImageConversion::QImage2RGBImage<int>(img);
    ImageProcessing::GrayImage<int> grayimg = ImageConversion::QImage2GrayImage<int>(img);

    ui->label->setPixmap(QPixmap::fromImage(ImageConversion::Bitmap2QImage(ImageProcessing::bitMap(grayimg.getGray(),150))));
    ui->label_2->setPixmap(QPixmap::fromImage(ImageConversion::GrayImage2QImage<int>(grayimg)));

    LinAlg::Matrix<int> hs1 = ImageProcessing::HistogramGray<int>(grayimg);
    LinAlg::Matrix<int> hs2 = ImageProcessing::HistogramRGB<int>(rgbimg);

    ///Plot e configuração do plot
    PlotHandler::plotProperties props;
    props.setLineStyle(QCPGraph::LineStyle::lsImpulse);
    props.setTitle("Cinza");
    props.setPlotFrame(ui->widget_2);
    PlotHandler::plot<int> t1 (LinAlg::LineVector<int>(0,255,1), hs1 ,props);
    PlotHandler::plotProperties props1;
    props1.setLineStyle(QCPGraph::LineStyle::lsImpulse);
    props1.setTitle("Red");
    props1.setPlotFrame(ui->widget_4);
    PlotHandler::plot<int> t2 (LinAlg::LineVector<int>(0,255,1), hs2.GetRow(1) ,props1);
    PlotHandler::plotProperties props2;
    props2.setLineStyle(QCPGraph::LineStyle::lsImpulse);
    props2.setTitle("Green");
    props2.setPlotFrame(ui->widget_3);
    PlotHandler::plot<int> t3 (LinAlg::LineVector<int>(0,255,1), hs2.GetRow(2) ,props2);
    PlotHandler::plotProperties props3;
    props3.setLineStyle(QCPGraph::LineStyle::lsImpulse);
    props3.setTitle("Blue");
    props3.setPlotFrame(ui->widget_5);
    PlotHandler::plot<int> t4 (LinAlg::LineVector<int>(0,255,1), hs2.GetRow(3) ,props3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
