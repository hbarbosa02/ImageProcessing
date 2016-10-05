#ifndef RGBIMAGE_H
#define RGBIMAGE_H

#include "QImage"
#include "QColor"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"

namespace ImageProcessing
{
    class RGBImage
    {
        public:
            RGBImage(){}
            RGBImage(const QImage &image); //ok
            RGBImage(LinAlg::Matrix<int> r,
                     LinAlg::Matrix<int> g,
                     LinAlg::Matrix<int> b);
//            RGBImage(LinAlg::Matrix<int> r,
//                     LinAlg::Matrix<int> g,
//                     LinAlg::Matrix<int> b,
//                     unsigned a);

            LinAlg::Matrix<int> getRed() const {return this->red;} //ok
            LinAlg::Matrix<int> getGreen() const {return this->green;} //ok
            LinAlg::Matrix<int> getBlue() const {return this->blue;} //ok
            LinAlg::Matrix<int> getGray() const {return this->gray;} //ok

            QImage redImage(); //ok
            QImage greenImage(); //ok
            QImage blueImage(); //ok
            QImage grayImage(); //ok

            unsigned Height() const {return this->height;} //ok
            unsigned Width() const {return this->width;} //ok

            //Criar operações com RGBImage:
            ImageProcessing::RGBImage& operator=  (const ImageProcessing::RGBImage& OtherRGBImage); //não foi testada
//            ImageProcessing::RGBImage& operator+=  (const ImageProcessing::RGBImage& OtherRGBImage){} //não foi testada
            ImageProcessing::RGBImage& operator+=  (const int& rhs); //não foi testada
//            ImageProcessing::RGBImage& operator-=  (const ImageProcessing::RGBImage& OtherRGBImage){} //não foi testada
            ImageProcessing::RGBImage& operator-=  (const int& rhs); //não foi testada
//            ImageProcessing::RGBImage& operator*=  (const ImageProcessing::RGBImage& OtherRGBImage){} //não foi testada
            ImageProcessing::RGBImage& operator*=  (const int& rhs); //não foi testada
//             ImageProcessing::RGBImage& operator/=  (const ImageProcessing::RGBImage& OtherRGBImage){} //não foi testada
            ImageProcessing::RGBImage& operator/=  (const int& rhs); //não foi testada


        private:
            LinAlg::Matrix<int> red, green, blue, gray;
            unsigned height, width, a;

            void initRGB(const QImage &image); //ok
    };

    QImage rgbImg2QImage(RGBImage Imrgb); //ok
    QImage bitMap2Image(LinAlg::Matrix<int> imgBitMap); //ok

    //Criar operações com RGBImage:

    LinAlg::Matrix<int> bitMap(RGBImage rgbImg); //ok
    LinAlg::Matrix<int> Histogram(RGBImage img); //não foi testada
}
#include "TesteClasses/rgbimage.hpp"
#endif // RGBIMAGE_H
