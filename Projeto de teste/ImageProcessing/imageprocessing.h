#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "QColor"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace ImageProcessing
{
    template <typename Type>
    LinAlg::Matrix<Type> checkValue(const LinAlg::Matrix<Type> &mat);
    template <typename Type>
    LinAlg::Matrix<Type> GetColorPixel(const LinAlg::Matrix<Type> &r,
                                    const LinAlg::Matrix<Type> &g,
                                    const LinAlg::Matrix<Type> &b); //not ok
    template <typename Type>
    LinAlg::Matrix<Type> Histogram(const LinAlg::Matrix<Type> &img); //ok
    template <typename Type>
    LinAlg::Matrix<Type> ApplyingMask(const LinAlg::Matrix<Type> &mat, const LinAlg::Matrix<Type> &mask);
    template<typename Type>
    LinAlg::Matrix<Type> negative(const LinAlg::Matrix<Type> &mat);
    template <typename Type>
    LinAlg::Matrix<Type> Rotation(const LinAlg::Matrix<Type> &mat, const double &angle);
    template <typename Type>
    LinAlg::Matrix<Type> Scale(const LinAlg::Matrix<Type> &mat, const double &scale);
    template <typename Type>
    LinAlg::Matrix<Type> Reflect(const LinAlg::Matrix<Type> &mat, bool flag = false);
    template <typename Type>
    LinAlg::Matrix<Type> MediaFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask);
    template <typename Type>
    LinAlg::Matrix<Type> MedianFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask);
    template <typename Type>
    LinAlg::Matrix<Type> GaussianFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask, const double step);
    template <typename Type>
    LinAlg::Matrix<Type> SelfReinforcementFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask, const double &a);

    template<typename Type>
    LinAlg::Matrix<bool> im2bw(const LinAlg::Matrix<Type> &mat, const unsigned &limiar);
    template <typename Type>
    LinAlg::Matrix<bool> Erosion(const LinAlg::Matrix<bool> &mat);
    template <typename Type>
    LinAlg::Matrix<Type> ErosionMask(const LinAlg::Matrix<Type> &mat, const unsigned &row, const unsigned &col);


    template <typename Type>
    unsigned bound(LinAlg::Matrix<bool> &mat);

    template <typename Type>
    int GetColorPixel(const Type &r,const Type &g, const Type &b); //ok

}
#include "ImageProcessing/imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
