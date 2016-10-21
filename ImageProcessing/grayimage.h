#ifndef GRAYIMAGE_H
#define GRAYIMAGE_H

#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "ImageProcessing/imageprocessing.h"

namespace ImageProcessing {
    template <class Type>
    class GrayImage
    {
        public:
            GrayImage(){}
            GrayImage(const LinAlg::Matrix<Type> &gray);
            ~GrayImage();

            LinAlg::Matrix<Type> getGray() const {return this->gray;}

            unsigned getWidth() const {return this->width;}
            unsigned getHeight()const {return this->height;}

            ImageProcessing::GrayImage<Type>& operator= (const ImageProcessing::GrayImage<Type> &grayImg);
            template<typename RightType>
            ImageProcessing::GrayImage<Type>& operator= (const ImageProcessing::GrayImage<RightType>& grayImg);

            ImageProcessing::GrayImage<Type>& operator+= (const ImageProcessing::GrayImage<Type>& grayImg);
            ImageProcessing::GrayImage<Type>& operator+= (const Type& value);
            template<typename RightType>
            ImageProcessing::GrayImage<Type>& operator+= (const RightType& value);

            ImageProcessing::GrayImage<Type>& operator-= (const ImageProcessing::GrayImage<Type>& grayImg);
            ImageProcessing::GrayImage<Type>& operator-= (const Type& value);
            template<typename RightType>
            ImageProcessing::GrayImage<Type>& operator-= (const RightType& value);

            ImageProcessing::GrayImage<Type>& operator*= (const ImageProcessing::GrayImage<Type>& grayImg);
            ImageProcessing::GrayImage<Type>& operator*= (const Type& value);
            template<typename RightType>
            ImageProcessing::GrayImage<Type>& operator*= (const RightType& value);

            ImageProcessing::GrayImage<Type>& operator/= (const Type& value);
            template<typename RightType>
            ImageProcessing::GrayImage<Type>& operator/= (const RightType& value);

            ImageProcessing::GrayImage<Type>& operator<= (const Type& value);
            ImageProcessing::GrayImage<Type>& operator>= (const Type& value);

        private:
            LinAlg::Matrix<Type> gray;
            unsigned height, width, a;
    };

    template <class Type>
    ImageProcessing::GrayImage<Type> operator +(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs += rhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator +(ImageProcessing::GrayImage<Type> lhs,const OtherType& rhs){return lhs += rhs;}
    template <class Type>
    ImageProcessing::GrayImage<Type> operator +(const Type& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs += lhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator +(const OtherType& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs += lhs;}
    template <class Type>
    ImageProcessing::GrayImage<Type> operator +(ImageProcessing::GrayImage<Type> lhs,ImageProcessing::GrayImage<Type> rhs){return lhs += rhs;}

    template <class Type>
    ImageProcessing::GrayImage<Type> operator -(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs -= rhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator -(ImageProcessing::GrayImage<Type> lhs,const OtherType& rhs){return lhs -= rhs;}
    template <class Type>
    ImageProcessing::GrayImage<Type> operator -(const Type& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs -= lhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator -(const OtherType& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs -= lhs;}
    template <class Type>
    ImageProcessing::GrayImage<Type> operator -(ImageProcessing::GrayImage<Type> lhs,ImageProcessing::GrayImage<Type> rhs){return lhs -= rhs;}

    template <class Type>
    ImageProcessing::GrayImage<Type> operator *(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs *= rhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator *(ImageProcessing::GrayImage<Type> lhs,const OtherType& rhs){return lhs *= rhs;}
    template <class Type>
    ImageProcessing::GrayImage<Type> operator *(const Type& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs *= lhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator *(const OtherType& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs *= lhs;}
    template <class Type>
    ImageProcessing::GrayImage<Type> operator *(ImageProcessing::GrayImage<Type> lhs,ImageProcessing::GrayImage<Type> rhs){return lhs *= rhs;}

    template <class Type>
    ImageProcessing::GrayImage<Type> operator /(ImageProcessing::GrayImage<Type> lhs,const Type& rhs){return lhs /= rhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator /(ImageProcessing::GrayImage<Type> lhs,const OtherType& rhs){return lhs /= rhs;}
    template <class Type>
    ImageProcessing::GrayImage<Type> operator /(const Type& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs /= lhs;}
    template <class Type, class OtherType>
    ImageProcessing::GrayImage<Type> operator /(const OtherType& lhs,ImageProcessing::GrayImage<Type> rhs){return rhs /= lhs;}

    template <class Type>
    LinAlg::Matrix<Type> HistogramGray(const ImageProcessing::GrayImage<Type> &grayimg); //ok
    template <class Type>
    ImageProcessing::GrayImage<Type> Rotation(const ImageProcessing::GrayImage<Type> &grayimg, const double &angle);
    template <class Type>
    ImageProcessing::GrayImage<Type> Scale(const ImageProcessing::GrayImage<Type> &grayimg, const double &scale);
    template <class Type>
    ImageProcessing::GrayImage<Type> ReflectLtoR(const ImageProcessing::GrayImage<Type> &grayimg);
    template <class Type>
    ImageProcessing::GrayImage<Type> ReflectUtoD(const ImageProcessing::GrayImage<Type> &grayimg);
}
#include "ImageProcessing/grayimage.hpp"
#endif // GRAYIMAGE_H
