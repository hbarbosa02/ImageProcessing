#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include "QColor"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace LinAlg{

    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> sumPointToPoint(const LinAlg::Matrix<Type> &left, const LinAlg::Matrix<OtherType> &right)
    {
        LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(left.getNumberOfRows(),left.getNumberOfColumns());

        for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i){
            for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
                ret(i,j) = left(i,j)+right(i,j);
            }
        }
        return ret;
    }
    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> subPointToPoint(const LinAlg::Matrix<Type> &left, const LinAlg::Matrix<OtherType> &right)
    {
        LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(left.getNumberOfRows(),left.getNumberOfColumns());

        for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i){
            for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
                ret(i,j) = left(i,j)-right(i,j);
            }
        }
        return ret;
    }
    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> multPointToPoint(const LinAlg::Matrix<Type> &left, const LinAlg::Matrix<OtherType> &right)
    {
        LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(left.getNumberOfRows(),left.getNumberOfColumns());

        for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i){
            for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
                ret(i,j) = left(i,j)*right(i,j);
            }
        }
        return ret;
    }
}

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
    template <typename Type, typename OtherType>
    LinAlg::Matrix<Type> ApplyingMask(const LinAlg::Matrix<Type> &mat, const LinAlg::Matrix<OtherType> &mask);
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
    LinAlg::Matrix<Type> GaussianFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask, double step = 1);
    template <typename Type>
    LinAlg::Matrix<Type> SelfReinforcementFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask, double a = 1);

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

    //testes
    template <typename Type>
    LinAlg::Matrix<Type> completing(const LinAlg::Matrix<Type> &mat, const unsigned &sizemask)
    {
        unsigned n = (int)sizemask/2;
        LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(mat.getNumberOfRows()+n*2,mat.getNumberOfColumns()+n*2);

        for(unsigned i = n; i <= ret.getNumberOfRows()-n-1; ++i)
            for(unsigned j = n; j <= ret.getNumberOfColumns()-n-1; ++j)
                ret(i+1,j+1) = mat(abs(i-n+1),abs(j-n+1));

        return ret;
    }
    template <typename Type>
    LinAlg::Matrix<Type> pullingOut(const LinAlg::Matrix<Type> &completingMat, const unsigned &sizemask)
    {
        unsigned n = (unsigned)sizemask/2;
        LinAlg::Matrix<Type> ret;
        ret = completingMat(from(n+1)-->completingMat.getNumberOfRows()-n,from(n+1)-->completingMat.getNumberOfColumns()-n);
        return ret;
    }
}
#include "ImageProcessing/imageprocessing.hpp"
#endif // IMAGEPROCESSING_H
