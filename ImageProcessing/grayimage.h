#ifndef GRAYIMAGE_H
#define GRAYIMAGE_H

#include "ImageProcessing/imageprocessing.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

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

        private:
            LinAlg::Matrix<Type> gray;
            unsigned height, width, a;
    };

    template <class Type>
    ImageProcessing::GrayImage<Type> QImage2GrayImage(const QImage &img); //ok
    template <class Type>
    LinAlg::Matrix<Type> HistogramGray(const ImageProcessing::GrayImage<Type> &grayimg); //ok
}
#include "ImageProcessing/grayimage.hpp"
#endif // GRAYIMAGE_H
