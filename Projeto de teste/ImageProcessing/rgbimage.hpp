#include "rgbimage.h"

template <class Type>
ImageProcessing::RGBImage<Type>::~RGBImage()
{

}

template <class Type>
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

template <class Type>
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

template <class Type>
LinAlg::Matrix<Type> ImageProcessing::HistogramRGB(const ImageProcessing::RGBImage<Type> &rgbimg)
{
    LinAlg::Matrix<Type> r = ImageProcessing::Histogram<Type>(rgbimg.getRed()),
                         g = ImageProcessing::Histogram<Type>(rgbimg.getGreen()),
                         b = ImageProcessing::Histogram<Type>(rgbimg.getBlue()),
                         ret = (r || g) || b;
    return  ret;
}

template <class Type>
ImageProcessing::RGBImage<Type> ImageProcessing::Rotation(const ImageProcessing::RGBImage<Type> &rgbimg, const double &angle)
{
    LinAlg::Matrix<Type> r = ImageProcessing::Rotation<Type>(rgbimg.getRed(),angle),
                         g = ImageProcessing::Rotation<Type>(rgbimg.getGreen(),angle),
                         b = ImageProcessing::Rotation<Type>(rgbimg.getBlue(),angle);

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}

template <class Type>
ImageProcessing::RGBImage<Type> ImageProcessing::Scale(const ImageProcessing::RGBImage<Type> &rgbimg, const double &scale)
{
    LinAlg::Matrix<Type> r = ImageProcessing::Scale<Type>(rgbimg.getRed(),scale),
                         g = ImageProcessing::Scale<Type>(rgbimg.getGreen(),scale),
                         b = ImageProcessing::Scale<Type>(rgbimg.getBlue(),scale);

    ImageProcessing::RGBImage<Type> ret(r,g,b);
    return ret;
}
