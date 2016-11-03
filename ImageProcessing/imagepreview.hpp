#include "ImageProcessing/ImageProcessing.h"

template <class Type>
void ImageProcessing::imShow(QImage img,QLabel *label)
{
    label->setPixmap(QPixmap::fromImage(img));
}

template <typename Type>
void ImageProcessing::imShow(ImageProcessing::GrayImage<Type> img,QLabel *label)
{
    QImage aux = ImageProcessing::GrayImage2QImage<Type>(img);
    label->setPixmap(QPixmap::fromImage(aux));
}

template <typename Type>
void ImageProcessing::imShow(ImageProcessing::RGBImage<Type> img,QLabel *label)
{
    QImage aux = ImageProcessing::RGBImage2QImage<Type>(img);
    label->setPixmap(QPixmap::fromImage(aux));
}

template <typename Type>
void ImageProcessing::imShow(LinAlg::Matrix<Type> img,QLabel *label)
{
    QImage aux = ImageProcessing::Bitmap2QImage<Type>(img);
    label->setPixmap(QPixmap::fromImage(aux));
}

template <typename Type>
void ImageProcessing::plot(LinAlg::Matrix<Type> histograma, QWidget *widget)
{
    LinAlg::Matrix<Type> LV = LinAlg::LineVector<Type>(0,255,1);
    PlotHandler::plotProperties props;
    props.setPlotFrame(widget);
    props.setLineStyle(QCPGraph::LineStyle::lsLine);

    if(histograma.getNumberOfRows() < 2)
        PlotHandler::plot<Type> plot(LV,histograma,props);
    else
        std::cout << "RGB is not Funcional" << std::endl;
}

template <typename Type>
void ImageProcessing::bar(LinAlg::Matrix<Type> histograma, QWidget *widget)
{
    LinAlg::Matrix<Type> LV = LinAlg::LineVector<Type>(0,255,1);
    PlotHandler::plotProperties props;
    props.setPlotFrame(widget);
    props.setLineStyle(QCPGraph::LineStyle::lsImpulse);

    if(histograma.getNumberOfRows() < 2)
        PlotHandler::plot<Type> plot(LV,histograma,props);
    else
        std::cout << "RGB is not Funcional" << std::endl;
}
