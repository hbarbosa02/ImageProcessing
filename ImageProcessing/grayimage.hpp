#include "grayimage.h"

template <typename Type>
ImageProcessing::GrayImage<Type>::~GrayImage()
{

}

template <typename Type>
ImageProcessing::GrayImage<Type>::GrayImage(const LinAlg::Matrix<Type> &gray)
{
    this->gray = gray;

    this->width = gray.getNumberOfRows();
    this->height = gray.getNumberOfColumns();
    this->a = 255;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator =(const ImageProcessing::GrayImage<Type>& grayImg)
{
    this->gray = grayImg.getGray();
    this->width = grayImg.getWidth();
    this->height = grayImg.getHeight();
    this->a = 255;

    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator =(const ImageProcessing::GrayImage<OtherType>& grayImg)
{
    this->gray = grayImg.getGray();
    this->width = grayImg.getWidth();
    this->height = grayImg.getHeight();
    this->a = 255;

    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const Type& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const OtherType& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::sumPointToPoint<Type>(this->getGray(),grayImg.getGray());
    this->gray = ImageProcessing::checkValue<Type>(aux);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const Type& value)
{
    this->gray -= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const OtherType& value)
{
    this->gray -= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::subPointToPoint<Type>(this->getGray(),grayImg.getGray());
    this->gray = ImageProcessing::checkValue<Type>(aux);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const Type& value)
{
    this->gray *= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const OtherType& value)
{
    this->gray *= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::multPointToPoint<Type>(this->getGray(),grayImg.getGray());
    this->gray = ImageProcessing::checkValue<Type>(aux);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator /=(const Type& value)
{
    this->gray /= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator /=(const OtherType& value)
{
    this->gray /= value;
    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator ^=(const Type& value)
{
    for(unsigned i = 1; i <= this->width; ++i)
        for(unsigned j = 1; j <= this->height; ++j)
            this->gray(i,j) = this->gray(i,j)^value;

    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type> template<class OtherType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator ^=(const OtherType& value)
{
    for(unsigned i = 1; i <= this->width; ++i)
        for(unsigned j = 1; j <= this->height; ++j)
            this->gray(i,j) = this->gray(i,j)^value;

    this->gray = ImageProcessing::checkValue<Type>(this->gray);
    return *this;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::operator <=(ImageProcessing::GrayImage<Type> lhs, const Type& value)
{
    LinAlg::Matrix<Type> aux = ImageProcessing::BitMap(lhs.getGray(),value);
    LinAlg::Matrix<Type> aux1 = ImageProcessing::Negative<Type>(aux);
    ImageProcessing::GrayImage<Type> ret(aux1);
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::operator >=(ImageProcessing::GrayImage<Type> lhs, const Type& value)
{
    LinAlg::Matrix<Type> aux = ImageProcessing::BitMap(lhs.getGray(),value);
    ImageProcessing::GrayImage<Type> ret(aux);
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::HistogramGray(const ImageProcessing::GrayImage<Type> &grayimg)
{
    return ImageProcessing::Histogram<Type>(grayimg.getGray());
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::Rotation(const ImageProcessing::GrayImage<Type> &grayimg, const double &angle)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::Rotation<Type>(grayimg.getGray(),angle));
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::Scale(const ImageProcessing::GrayImage<Type> &grayimg, const double &scale)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::Scale<Type>(grayimg.getGray(),scale));
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::ReflectLtoR(const ImageProcessing::GrayImage<Type> &grayimg)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::ReflectLtoR(grayimg.getGray()));
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::ReflectUtoD(const ImageProcessing::GrayImage<Type> &grayimg)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::ReflectUtoD(grayimg.getGray()));
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::MediaFilter(const ImageProcessing::GrayImage<Type> &grayimg, const int &sizeMask)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::MediaFilter<Type>(grayimg.getGray(), sizeMask));
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::MedianFilter(const ImageProcessing::GrayImage<Type> &grayimg, const int &sizeMask)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::MedianFilter<Type>(grayimg.getGray(), sizeMask));
    return ret;
}

template <typename Type>
ImageProcessing::GrayImage<Type> ImageProcessing::SelfReinforcementFilter(const ImageProcessing::GrayImage<Type> &grayimg, const int &sizeMask, const double &a)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::SelfReinforcementFilter<Type>(grayimg.getGray(), sizeMask, a));
    return ret;
}