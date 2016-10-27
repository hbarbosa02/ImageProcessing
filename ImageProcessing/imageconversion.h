#ifndef IMAGECONVERSION_H
#define IMAGECONVERSION_H

#include "QImage"
#include "QColor"
#include "ImageProcessing/grayimage.h"
#include "ImageProcessing/rgbimage.h"

namespace ImageConversion
{
    template <typename Type>
    QImage RGBImage2QImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <typename Type>
    QImage GrayImage2QImage(const ImageProcessing::GrayImage<Type> &grayImg); //ok
    template <typename Type>
    QImage Bitmap2QImage(const LinAlg::Matrix<Type> bitmap); //ok
    template <typename Type>
    QImage RedImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <typename Type>
    QImage GreenImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <typename Type>
    QImage BlueImage(const ImageProcessing::RGBImage<Type> &rgbImg); //ok
    template <typename Type>
    QImage SetPixel(const LinAlg::Matrix<Type> &r,
                    const LinAlg::Matrix<Type> &g,
                    const LinAlg::Matrix<Type> &b); //ok

    template <typename Type>
    ImageProcessing::RGBImage<Type> QImage2RGBImage(const QImage &img); //ok
    template <typename Type>
    ImageProcessing::GrayImage<Type> QImage2GrayImage(const QImage &img); //ok
    template <typename Type>
    ImageProcessing::GrayImage<Type> RGBImage2GrayImage(const ImageProcessing::RGBImage<Type> &rgbimg);

}
#include "ImageProcessing/imageconversion.hpp"

#endif // IMAGECONVERSION_H
