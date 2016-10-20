#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "QImage"
#include "QColor"
#include "ImageProcessing/rgbimage.h"
#include "ImageProcessing/grayimage.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace ImageProcessing {

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
    int GetPixel(const Type &r,const Type &g, const Type &b); //ok

    template <class Type>
    LinAlg::Matrix<Type> Histogram(const LinAlg::Matrix<Type> &img); //ok
}
#include "ImageProcessing/imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
