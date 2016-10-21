#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "QColor"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace ImageProcessing {

    template <class Type>
    int GetColorPixel(const Type &r,const Type &g, const Type &b); //ok
    template <class Type>
    LinAlg::Matrix<Type> checkValue(const LinAlg::Matrix<Type> &mat);
    template <class Type>
    LinAlg::Matrix<Type> GetColorPixel(const LinAlg::Matrix<Type> &r,
                                    const LinAlg::Matrix<Type> &g,
                                    const LinAlg::Matrix<Type> &b); //not ok
    template <class Type>
    LinAlg::Matrix<Type> Histogram(const LinAlg::Matrix<Type> &img); //ok
    template <class Type>
    LinAlg::Matrix<Type> ApplyingMask(const LinAlg::Matrix<Type> &mat, const LinAlg::Matrix<Type> &mask);
    template<class Type>
    LinAlg::Matrix<Type> BitMap(const LinAlg::Matrix<Type> &mat, const unsigned &limiar);
    template<class Type>
    LinAlg::Matrix<Type> Negative(const LinAlg::Matrix<Type> &mat);
    template <class Type>
    LinAlg::Matrix<Type> Rotation(const LinAlg::Matrix<Type> &mat, const double &angle);
    template <class Type>
    LinAlg::Matrix<Type> Scale(const LinAlg::Matrix<Type> &mat, const double &scale);
    template <class Type>
    LinAlg::Matrix<Type> ReflectLtoR(const LinAlg::Matrix<Type> &mat);
    template <class Type>
    LinAlg::Matrix<Type> ReflectUtoD(const LinAlg::Matrix<Type> &mat);

}
#include "ImageProcessing/imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
