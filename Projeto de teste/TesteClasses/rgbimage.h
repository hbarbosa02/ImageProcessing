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

            LinAlg::Matrix<int> getRed(){return this->red;} //ok
            LinAlg::Matrix<int> getGreen(){return this->green;} //ok
            LinAlg::Matrix<int> getBlue(){return this->blue;} //ok
            LinAlg::Matrix<int> getGray(){return this->gray;} //ok

            QImage redImage(); //ok
            QImage greenImage(); //ok
            QImage blueImage(); //ok
            QImage grayImage(); //ok

            unsigned Height(){return this->height;} //ok
            unsigned Width(){return this->width;} //ok
            //Criar operações com RGBImage:

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
