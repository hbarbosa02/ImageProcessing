#include "rgbimage.h"

template <typename Type>
ImageProcessing::RGBImage<Type>::~RGBImage()
{

}

template <typename Type>
ImageProcessing::RGBImage<Type>::RGBImage(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b)
{
    this->red = r;
    this->green = g;
    this->blue = b;
    //this->rgb = ImageProcessing::GetPixel<Type>(r,g,b);

    this->width = r.getNumberOfRows();
    this->height = r.getNumberOfColumns();
    this->a = 255;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator =(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    this->width = rgbImg.getWidth();
    this->height = rgbImg.getHeight();

    this->red = rgbImg.getRed();
    this->green = rgbImg.getGreen();
    this->blue = rgbImg.getBlue();

    this->a = 255;

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator +=(const Type& value)
{
    this->red += value;
    this->green += value;
    this->blue += value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator +=(const OtherType& value)
{
    this->red += value;
    this->green += value;
    this->blue += value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator +=(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::sumPointToPoint<Type>(this->red,rgbImg.getRed());
    this->red = ImageProcessing::checkValue<Type>(aux);

    aux = LinAlg::sumPointToPoint<Type>(this->green,rgbImg.getGreen());
    this->green = ImageProcessing::checkValue<Type>(aux);

    aux = LinAlg::sumPointToPoint<Type>(this->blue,rgbImg.getBlue());
    this->blue = ImageProcessing::checkValue<Type>(aux);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator -=(const Type& value)
{
    this->red -= value;
    this->green -= value;
    this->blue -= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator -=(const OtherType& value)
{
    this->red -= value;
    this->green -= value;
    this->blue -= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator -=(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::subPointToPoint<Type>(this->red,rgbImg.getRed());
    this->red = ImageProcessing::checkValue<Type>(aux);

    aux = LinAlg::subPointToPoint<Type>(this->green,rgbImg.getGreen());
    this->green = ImageProcessing::checkValue<Type>(aux);

    aux = LinAlg::subPointToPoint<Type>(this->blue,rgbImg.getBlue());
    this->blue = ImageProcessing::checkValue<Type>(aux);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator *=(const Type& value)
{
    this->red *= value;
    this->green *= value;
    this->blue *= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator *=(const OtherType& value)
{
    this->red *= value;
    this->green *= value;
    this->blue *= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator *=(const ImageProcessing::RGBImage<Type>& rgbImg)
{
    LinAlg::Matrix<Type> aux = LinAlg::multPointToPoint<Type>(this->red,rgbImg.getRed());
    this->red = ImageProcessing::checkValue<Type>(aux);

    aux = LinAlg::multPointToPoint<Type>(this->green,rgbImg.getGreen());
    this->green = ImageProcessing::checkValue<Type>(aux);

    aux = LinAlg::multPointToPoint<Type>(this->blue,rgbImg.getBlue());
    this->blue = ImageProcessing::checkValue<Type>(aux);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator /=(const Type& value)
{
    this->red /= value;
    this->green /= value;
    this->blue /= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator /=(const OtherType& value)
{
    this->red /= value;
    this->green /= value;
    this->blue /= value;

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator ^=(const Type& value)
{
    for(unsigned i = 1; i <= this->width; ++i)
        for(unsigned j = 1; j <= this->height; ++j)
        {
            this->red(i,j) = this->red(i,j)^value;
            this->green(i,j) = this->green(i,j)^value;
            this->blue(i,j) = this->blue(i,j)^value;
        }

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type> template<typename OtherType>
ImageProcessing::RGBImage<Type>& ImageProcessing::RGBImage<Type>::operator ^=(const OtherType& value)
{
    for(unsigned i = 1; i <= this->width; ++i)
        for(unsigned j = 1; j <= this->height; ++j)
        {
            this->red(i,j) = this->red(i,j)^value;
            this->green(i,j) = this->green(i,j)^value;
            this->blue(i,j) = this->blue(i,j)^value;
        }

    this->red = ImageProcessing::checkValue<Type>(this->red);
    this->green = ImageProcessing::checkValue<Type>(this->green);
    this->blue = ImageProcessing::checkValue<Type>(this->blue);

    return *this;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::HistogramRGB(const ImageProcessing::RGBImage<Type> &rgbimg)
{
    LinAlg::Matrix<Type> r = ImageProcessing::Histogram<Type>(rgbimg.getRed()),
                         g = ImageProcessing::Histogram<Type>(rgbimg.getGreen()),
                         b = ImageProcessing::Histogram<Type>(rgbimg.getBlue()),
                         ret = (r || g) || b;
    return  ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::Rotation(const ImageProcessing::RGBImage<Type> &rgbimg, const double &angle)
{
    LinAlg::Matrix<Type> r = ImageProcessing::Rotation<Type>(rgbimg.getRed(),angle),
                         g = ImageProcessing::Rotation<Type>(rgbimg.getGreen(),angle),
                         b = ImageProcessing::Rotation<Type>(rgbimg.getBlue(),angle);

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::Scale(const ImageProcessing::RGBImage<Type> &rgbimg, const double &scale)
{
    LinAlg::Matrix<Type> r = ImageProcessing::Scale<Type>(rgbimg.getRed(),scale),
                         g = ImageProcessing::Scale<Type>(rgbimg.getGreen(),scale),
                         b = ImageProcessing::Scale<Type>(rgbimg.getBlue(),scale);

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::ReflectLtoR(const ImageProcessing::RGBImage<Type> &rgbimg)
{
    LinAlg::Matrix<Type> r = ImageProcessing::ReflectLtoR<Type>(rgbimg.getRed()),
                         g = ImageProcessing::ReflectLtoR<Type>(rgbimg.getGreen()),
                         b = ImageProcessing::ReflectLtoR<Type>(rgbimg.getBlue());

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::ReflectUtoD(const ImageProcessing::RGBImage<Type> &rgbimg)
{
    LinAlg::Matrix<Type> r = ImageProcessing::ReflectUtoD<Type>(rgbimg.getRed()),
                         g = ImageProcessing::ReflectUtoD<Type>(rgbimg.getGreen()),
                         b = ImageProcessing::ReflectUtoD<Type>(rgbimg.getBlue());

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::MediaFilter(const ImageProcessing::RGBImage<Type> &rgbimg, const int &sizeMask)
{
    LinAlg::Matrix<Type> r = ImageProcessing::MediaFilter<Type>(rgbimg.getRed(),sizeMask),
                         g = ImageProcessing::MediaFilter<Type>(rgbimg.getGreen(),sizeMask),
                         b = ImageProcessing::MediaFilter<Type>(rgbimg.getBlue(),sizeMask);

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::MedianFilter(const ImageProcessing::RGBImage<Type> &rgbimg, const int &sizeMask)
{
    LinAlg::Matrix<Type> r = ImageProcessing::MedianFilter<Type>(rgbimg.getRed(),sizeMask),
                         g = ImageProcessing::MedianFilter<Type>(rgbimg.getGreen(),sizeMask),
                         b = ImageProcessing::MedianFilter<Type>(rgbimg.getBlue(),sizeMask);

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}

template <typename Type>
ImageProcessing::RGBImage<Type> ImageProcessing::SelfReinforcementFilter(const ImageProcessing::RGBImage<Type> &rgbimg, const int &sizeMask, const double &a)
{
    LinAlg::Matrix<Type> r = ImageProcessing::SelfReinforcementFilter<Type>(rgbimg.getRed(),sizeMask,a),
                         g = ImageProcessing::SelfReinforcementFilter<Type>(rgbimg.getGreen(),sizeMask,a),
                         b = ImageProcessing::SelfReinforcementFilter<Type>(rgbimg.getBlue(),sizeMask,a);

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}
