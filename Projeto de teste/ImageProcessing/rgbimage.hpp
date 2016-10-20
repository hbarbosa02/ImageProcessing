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
    this->rgb = ImageProcessing::GetPixel<Type>(r,g,b);

    this->width = r.getNumberOfRows();
    this->height = r.getNumberOfColumns();
    this->a = 255;
}

template <class Type>
ImageProcessing::RGBImage<Type> ImageProcessing::QImage2RGBImage(const QImage &img)
{
    LinAlg::Matrix<Type> r(img.width(),img.height()), g(img.width(),img.height()), b(img.width(),img.height());

    for(unsigned i = 0; i < img.width(); ++i)
            for(unsigned j = 0; j < img.height(); ++j){
                QColor color(img.pixel(i,j));
                r(i+1,j+1) = color.red();
                g(i+1,j+1) = color.green();
                b(i+1,j+1) = color.blue();
            }

    ImageProcessing::RGBImage<Type> ret(r,g,b);

    return ret;
}

template <class Type>
LinAlg::Matrix<Type> ImageProcessing::HistogramRGB(const ImageProcessing::RGBImage<Type> &rgbimg)
{
    LinAlg::Matrix<int> ret(3,256), r = rgbimg.getRed(), g = rgbimg.getGreen(), b = rgbimg.getBlue();

    for(unsigned i = 1; i <= rgbimg.getWidth(); ++i)
        for(unsigned j = 1; j <= rgbimg.getHeight(); ++j)
        {
            int rk = r(i,j), gk = g(i,j), bk = b(i,j);
            ret(1,rk) += 1;
            ret(2,gk) += 1;
            ret(3,bk) += 1;
        }

    return ret;
}


template <class Type>
LinAlg::Matrix<int> ImageProcessing::GetPixel(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b)
{
    LinAlg::Matrix<int> ret(r.getNumberOfRows(),r.getNumberOfColumns());

    for(unsigned i = 1; i <= r.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= r.getNumberOfColumns(); ++j)
            ret(i,j) = QColor(r(i,j),g(i,j),b(i,j)).value();

    return ret;
}
