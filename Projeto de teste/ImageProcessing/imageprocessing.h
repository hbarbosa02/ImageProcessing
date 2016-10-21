#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "QColor"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace ImageProcessing {

    template <class Type>
    int GetColorPixel(const Type &r,const Type &g, const Type &b); //ok
    template <class Type>
    LinAlg::Matrix<Type> GetColorPixel(const LinAlg::Matrix<Type> &r,
                                    const LinAlg::Matrix<Type> &g,
                                    const LinAlg::Matrix<Type> &b); //not ok
    template <class Type>
    LinAlg::Matrix<Type> Histogram(const LinAlg::Matrix<Type> &img); //ok
    template <typename Type>
    LinAlg::Matrix<Type> applyingMask(const LinAlg::Matrix<Type> &mat, const LinAlg::Matrix<Type> &mask);
    template<typename Type>
    LinAlg::Matrix<Type> bitMap(const LinAlg::Matrix<Type> &mat, const unsigned &limiar);
    template <class Type>
    LinAlg::Matrix<Type> Rotation(const LinAlg::Matrix<Type> &mat, const double &angle);
    template <class Type>
    LinAlg::Matrix<Type> Scale(const LinAlg::Matrix<Type> &mat, const double &scale);

}
#include "ImageProcessing/imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
