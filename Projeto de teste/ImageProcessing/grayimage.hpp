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
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(1,256), gray = grayimg.getGray();

    for(unsigned i = 1; i <= grayimg.getWidth(); ++i)
        for(unsigned j = 1; j <= grayimg.getHeight(); ++j)
        {
            unsigned k = gray(i,j);
            ret(1,k) += 1;
        }

    return ret;
}

template <class Type>
ImageProcessing::GrayImage<Type> ImageProcessing::Rotation(const ImageProcessing::GrayImage<Type> &grayimg, const double &angle)
{
    LinAlg::Matrix<Type> temp(grayimg.getWidth(),grayimg.getHeight()), rot(2,2), p1(2,1), p2(2,1), pos;
    LinAlg::Matrix<Type> gray = ~grayimg.getGray();

    double ang  = angle * M_PI/180;

    rot(1,1) = cos(ang); rot(1,2) = sin(ang);
    rot(2,1) = -sin(ang); rot(2,2) = cos(ang);

    p2(1,1) = grayimg.getHeight()/2;
    p2(2,1) = grayimg.getWidth()/2;

    for(unsigned i = 1; i <= temp.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= temp.getNumberOfColumns(); ++j){
            p1(1,1) = i - p2(2,1);
            p1(2,1) = j - p2(1,1);

            pos = (rot *p1) + p2;

            if(pos(2,1)>0 && pos(2,1) <= grayimg.getWidth() && pos(1,1)>0 && pos(1,1) <= grayimg.getHeight())
                temp(i,j) = gray(pos(2,1),pos(1,1));
        }

    ImageProcessing::GrayImage<Type> ret(temp);
    return ret;
}
