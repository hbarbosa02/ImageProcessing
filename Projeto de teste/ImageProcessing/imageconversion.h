#ifndef IMAGECONVERSION_H
#define IMAGECONVERSION_H

#include "QImage"
#include "QColor"
#include "ImageProcessing/grayimage.h"
#include "ImageProcessing/rgbimage.h"

namespace ImageConversion
{
    template <class Type>
    QImage RGBImage2QImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <class Type>
    QImage GrayImage2QImage(const ImageProcessing::GrayImage<Type> &grayImg); //ok
    template <class Type>
    QImage Bitmap2QImage(const LinAlg::Matrix<Type> bitmap); //ok
    template <class Type>
    QImage RedImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <class Type>
    QImage GreenImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <class Type>
    QImage BlueImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <class Type>
    QImage SetPixel(const LinAlg::Matrix<Type> &r,
                    const LinAlg::Matrix<Type> &g,
                    const LinAlg::Matrix<Type> &b); //ok

    template <class Type>
    ImageProcessing::RGBImage<Type> QImage2RGBImage(const QImage &img); //ok
    template <class Type>
    ImageProcessing::GrayImage<Type> QImage2GrayImage(const QImage &img); //ok
    template <class Type>
    ImageProcessing::GrayImage<Type> RGBImage2GrayImage(const ImageProcessing::RGBImage<Type> &rgbimg);

}
#include "ImageProcessing/imageconversion.hpp"

#endif // IMAGECONVERSION_H
