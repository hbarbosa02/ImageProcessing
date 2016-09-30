#ifndef RGBIMAGE_H
#define RGBIMAGE_H

#include "QImage"
#include "QColor"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace ImageProcessing {
    class RGBImage
    {
        public:
            RGBImage(){}
            RGBImage(const QImage &image); //ok

            LinAlg::Matrix<int> getRed(){return this->red;} //ok
            LinAlg::Matrix<int> getGreen(){return this->green;} //ok
            LinAlg::Matrix<int> getBlue(){return this->blue;} //ok
            LinAlg::Matrix<int> getGray(){return this->gray;} //ok

            unsigned Height(){return this->height;} //ok
            unsigned Width(){return this->width;} //ok

        private:
            LinAlg::Matrix<int> red, green, blue, gray;
            unsigned height, width;

            void initRGB(const QImage &image); //ok
    };

    QImage rgbImg2QImage(RGBImage &Imrgb); //ok


    QImage bitMap2Image(const LinAlg::Matrix<int> &imgBitMap); //com problema
    LinAlg::Matrix<int> bitMap(RGBImage &rgbImg); //com problema
}
#include "TesteClasses/rgbimage.hpp"
#endif // RGBIMAGE_H
