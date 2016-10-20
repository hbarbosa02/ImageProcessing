#include "grayimage.h"

template <class Type>
ImageProcessing::GrayImage<Type>::~GrayImage()
{

}

template <class Type>
ImageProcessing::GrayImage<Type>::GrayImage(const LinAlg::Matrix<Type> &gray)
{
    this->gray = gray;

    this->width = gray.getNumberOfRows();
    this->height = gray.getNumberOfColumns();
    this->a = 255;
}

template <class Type>
ImageProcessing::GrayImage<Type> ImageProcessing::QImage2GrayImage(const QImage &img)
{
    LinAlg::Matrix<Type> gray(img.width(),img.height());
    for(unsigned i = 0; i < img.width(); ++i)
            for(unsigned j = 0; j < img.height(); ++j){
                QColor color(img.pixel(i,j));
                gray(i+1,j+1) = qGray(color.red(),color.green(),color.blue());
            }

    ImageProcessing::GrayImage<Type> ret(gray);
    return ret;
}

template <class Type>
LinAlg::Matrix<Type> HistogramGray(const ImageProcessing::GrayImage<Type> &grayimg)
{
    LinAlg::Matrix<int> ret = LinAlg::Zeros<int>(1,256), gray = grayimg.getGray();

    for(unsigned i = 1; i <= grayimg.getWidth(); ++i)
        for(unsigned j = 1; j <= grayimg.getHeight(); ++j)
        {
            int k = gray(i,j);
            ret(1,k) += 1;
        }

    return ret;
}
