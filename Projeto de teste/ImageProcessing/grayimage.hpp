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
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator =(const ImageProcessing::GrayImage<Type>& grayImg)
{
    this->gray = grayImg.getGray();
    this->width = grayImg.getWidth();
    this->height = grayImg.getHeight();
    this->a = 255;

    return *this;
}

template <class Type>
LinAlg::Matrix<Type> ImageProcessing::HistogramGray(const ImageProcessing::GrayImage<Type> &grayimg)
{
    return ImageProcessing::Histogram<Type>(grayimg.getGray());
}

template <class Type>
ImageProcessing::GrayImage<Type> ImageProcessing::Rotation(const ImageProcessing::GrayImage<Type> &grayimg, const double &angle)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::Rotation<Type>(grayimg.getGray(),angle));
    return ret;
}

template <class Type>
ImageProcessing::GrayImage<Type> ImageProcessing::Scale(const ImageProcessing::GrayImage<Type> &grayimg, const double &scale)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::Scale<Type>(grayimg.getGray(),scale));

    return ret;
}
