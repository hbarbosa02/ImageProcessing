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

            ImageProcessing::GrayImage<Type>& operator= (const ImageProcessing::GrayImage<Type>& grayImg);

        private:
            LinAlg::Matrix<Type> gray;
            unsigned height, width, a;
    };

    template <class Type>
    LinAlg::Matrix<Type> HistogramGray(const ImageProcessing::GrayImage<Type> &grayimg); //ok
    template <class Type>
    ImageProcessing::GrayImage<Type> Rotation(const ImageProcessing::GrayImage<Type> &grayimg, const double &angle);
    template <class Type>
    ImageProcessing::GrayImage<Type> Scale(const ImageProcessing::GrayImage<Type> &grayimg, const double &scale);
}
#include "ImageProcessing/grayimage.hpp"
#endif // GRAYIMAGE_H
