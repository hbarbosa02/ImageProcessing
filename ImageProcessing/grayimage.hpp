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

template <class Type> template<typename RightType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator =(const ImageProcessing::GrayImage<RightType>& grayImg)
{
    this->gray = grayImg.getGray();
    this->width = grayImg.getWidth();
    this->height = grayImg.getHeight();
    this->a = 255;

    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const Type& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type> template<typename RightType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const RightType& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator +=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::sumPointToPoint(this->getGray(),grayImg.getGray());
    this->gray = ImageProcessing::checkValue(aux);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const Type& value)
{
    this->gray -= value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type> template<typename RightType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const RightType& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator -=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::subPointToPoint(this->getGray(),grayImg.getGray());
    this->gray = ImageProcessing::checkValue(aux);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const Type& value)
{
    this->gray *= value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type> template<typename RightType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const RightType& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator *=(const ImageProcessing::GrayImage<Type>& grayImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::multPointToPoint(this->getGray(),grayImg.getGray());
    this->gray = ImageProcessing::checkValue(aux);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator /=(const Type& value)
{
    this->gray /= value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type> template<typename RightType>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator /=(const RightType& value)
{
    this->gray += value;
    this->gray = ImageProcessing::checkValue(this->gray);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator <=(const Type& value)
{
    LinAlg::Matrix<Type> aux = ImageProcessing::BitMap(this->gray,value);
    this->gray = ImageProcessing::Negative(aux);
    return *this;
}

template <class Type>
ImageProcessing::GrayImage<Type>& ImageProcessing::GrayImage<Type>::operator >=(const Type& value)
{
    this->gray = ImageProcessing::BitMap(this->gray,value);
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

template <class Type>
ImageProcessing::GrayImage<Type> ImageProcessing::ReflectLtoR(const ImageProcessing::GrayImage<Type> &grayimg)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::ReflectLtoR(grayimg.getGray()));
    return ret;
}

template <class Type>
ImageProcessing::GrayImage<Type> ImageProcessing::ReflectUtoD(const ImageProcessing::GrayImage<Type> &grayimg)
{
    ImageProcessing::GrayImage<Type> ret(ImageProcessing::ReflectUtoD(grayimg.getGray()));
    return ret;
}
