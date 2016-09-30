#include "rgbimage.h"

ImageProcessing::RGBImage::RGBImage(const QImage &image)
{
    this->height = image.height();
    this->width = image.width();

    this->initRGB(image);
}

void ImageProcessing::RGBImage::initRGB(const QImage &image)
{
    this->blue = LinAlg::Zeros<int>(this->Height(),this->Width());
    this->green = LinAlg::Zeros<int>(this->Height(),this->Width());
    this->red = LinAlg::Zeros<int>(this->Height(),this->Width());
    this->gray = LinAlg::Zeros<int>(this->Height(),this->Width());

    for(unsigned i = 0; i < this->Height(); ++i)
        for(unsigned j = 0; j < this->Width(); ++j)
        {
            QColor color(image.pixel(i,j));
            this->red(i+1,j+1) = color.red();
            this->green(i+1,j+1) = color.green();
            this->blue(i+1,j+1) = color.blue();
            this->gray(i+1,j+1) = qGray(this->red(i+1,j+1),this->green(i+1,j+1),this->blue(i+1,j+1));
        }
}

QImage ImageProcessing::RGBImage::getRedImage()
{
    QImage redImg(this->Height(), this->Width(),QImage::Format_RGB32);

    for(unsigned i = 0; i < this->Height(); ++i)
        for(unsigned j = 0; j < this->Width(); ++j)
        {
            QRgb color = qRgb(this->red(i+1,j+1),this->green(i+1,j+1),this->blue(i+1,j+1));
            redImg.setPixel(i,j,qRed(color));
        }
}

QImage ImageProcessing::bitMap2Image(const LinAlg::Matrix<int> &imgBitMap)
{
    QImage img(imgBitMap.getNumberOfRows(),imgBitMap.getNumberOfColumns(),QImage::Format_RGB32);

    for(unsigned i = 0; i < imgBitMap.getNumberOfRows(); ++i)
        for(unsigned j = 0; j < imgBitMap.getNumberOfColumns(); ++j)
            img.setPixel(i,j,imgBitMap(i+1,j+1));

    return img;
}

LinAlg::Matrix<int> ImageProcessing::bitMap(ImageProcessing::RGBImage &rgbImg)
{
    LinAlg::Matrix<int> bitMap(rgbImg.Height(), rgbImg.Width());

    for(unsigned i = 1; i <= bitMap.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= bitMap.getNumberOfColumns(); ++j)
        {
            if(rgbImg.getGray()(i,j) < 120)
                bitMap(i,j) = 0;
            else
                bitMap(i,j) = 1;
        }

    return bitMap;
}
