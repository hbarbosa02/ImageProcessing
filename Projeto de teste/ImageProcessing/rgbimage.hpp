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
    LinAlg::Matrix<Type> ret(3,256), r = rgbimg.getRed(), g = rgbimg.getGreen(), b = rgbimg.getBlue();

    for(unsigned i = 1; i <= rgbimg.getWidth(); ++i)
        for(unsigned j = 1; j <= rgbimg.getHeight(); ++j)
        {
            unsigned rk = r(i,j), gk = g(i,j), bk = b(i,j);
            ret(1,rk) += 1;
            ret(2,gk) += 1;
            ret(3,bk) += 1;
        }

    return ret;
}

template <class Type>
ImageProcessing::RGBImage<Type> ImageProcessing::Rotation(const ImageProcessing::RGBImage<Type> &rgbimg, const double &angle)
{
    LinAlg::Matrix<int> pos;

    LinAlg::Matrix<Type> t1(rgbimg.getWidth(),rgbimg.getHeight()),
                        t2(rgbimg.getWidth(),rgbimg.getHeight()),
                        t3(rgbimg.getWidth(),rgbimg.getHeight()),
                        rot(2,2), p1(2,1), p2(2,1);

    LinAlg::Matrix<Type> r = ~rgbimg.getRed(),
                        g = ~rgbimg.getGreen(),
                        b = ~rgbimg.getBlue();

    double ang  = angle * M_PI/180;

    rot(1,1) = cos(ang); rot(1,2) = sin(ang);
    rot(2,1) = -sin(ang); rot(2,2) = cos(ang);

    p2(1,1) = rgbimg.getHeight()/2;
    p2(2,1) = rgbimg.getWidth()/2;

    for(unsigned i = 1; i <= t1.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= t1.getNumberOfColumns(); ++j){
            p1(1,1) = i - p2(2,1);
            p1(2,1) = j - p2(1,1);

            pos = (rot *p1) + p2;

            if(pos(2,1)>0 && pos(2,1) <= rgbimg.getWidth() && pos(1,1)>0 && pos(1,1) <= rgbimg.getHeight())
            {
                t1(i,j) = r(pos(2,1),pos(1,1));
                t2(i,j) = g(pos(2,1),pos(1,1));
                t3(i,j) = b(pos(2,1),pos(1,1));
            }
        }

    ImageProcessing::RGBImage<Type> ret(t1,t2,t3);
    return ret;
}

