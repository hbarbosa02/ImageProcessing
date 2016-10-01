#include "rgbimage.h"

ImageProcessing::RGBImage::RGBImage(const QImage &image)
{
    this->height = image.height();
    this->width = image.width();
    this->a = 255;

    this->initRGB(image);
}

ImageProcessing::RGBImage::RGBImage(LinAlg::Matrix<int> r, LinAlg::Matrix<int> g, LinAlg::Matrix<int> b)
{
    this->height = r.getNumberOfRows();
    this->width = r.getNumberOfColumns();
    this->a = 255;

    this->red = r;
    this->green = g;
    this->blue = b;

    for(unsigned i = 0; i < this->height; ++i)
        for(unsigned j = 0; j < this->width; ++j)
            this->gray(i+1,j+1) = qGray(this->red(i+1,j+1),this->green(i+1,j+1),this->blue(i+1,j+1));
}

void ImageProcessing::RGBImage::initRGB(const QImage &image)
{
    this->blue = LinAlg::Zeros<int>(this->Height(),this->Width());
    this->green = LinAlg::Zeros<int>(this->Height(),this->Width());
    this->red = LinAlg::Zeros<int>(this->Height(),this->Width());
    this->gray = LinAlg::Zeros<int>(this->Height(),this->Width());

    for(unsigned i = 0; i < this->height; ++i)
        for(unsigned j = 0; j < this->width; ++j)
        {
            QColor color(image.pixel(i,j));
            this->red(i+1,j+1) = color.red();
            this->green(i+1,j+1) = color.green();
            this->blue(i+1,j+1) = color.blue();
            this->gray(i+1,j+1) = qGray(this->red(i+1,j+1),this->green(i+1,j+1),this->blue(i+1,j+1));
        }
}

QImage ImageProcessing::RGBImage::redImage()
{
    QImage img(this->height,this->width,QImage::Format_RGB32);

    for(unsigned i = 0; i < this->height; ++i)
        for(unsigned j = 0; j < this->width; ++j)
            img.setPixel(i,j,QColor(this->red(i+1,j+1),0,0).rgb());

    return img;
}

QImage ImageProcessing::RGBImage::greenImage()
{
    QImage img(this->height,this->width,QImage::Format_RGB32);

    for(unsigned i = 0; i < this->height; ++i)
        for(unsigned j = 0; j < this->width; ++j)
            img.setPixel(i,j,QColor(0,this->green(i+1,j+1),0).rgb());

    return img;
}

QImage ImageProcessing::RGBImage::blueImage()
{
    QImage img(this->height,this->width,QImage::Format_RGB32);

    for(unsigned i = 0; i < this->height; ++i)
        for(unsigned j = 0; j < this->width; ++j)
            img.setPixel(i,j,QColor(0,0,this->blue(i+1,j+1)).rgb());

    return img;
}

QImage ImageProcessing::RGBImage::grayImage()
{
    QImage img(this->height,this->width,QImage::Format_RGB32);

    for(unsigned i = 0; i < this->height; ++i)
        for(unsigned j = 0; j < this->width; ++j)
            img.setPixel(i,j,QColor(this->getGray()(i+1,j+1),
                                    this->getGray()(i+1,j+1),
                                    this->getGray()(i+1,j+1)).rgb());

    return img;
}

///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
QImage ImageProcessing::rgbImg2QImage(RGBImage &Imrgb)
{
    QImage img(Imrgb.Height(),Imrgb.Width(),QImage::Format_RGB32);

    for(unsigned i = 0; i < Imrgb.Height(); ++i)
        for(unsigned j = 0; j < Imrgb.Width(); ++j)
        {
            QColor color(Imrgb.getRed()(i+1,j+1),
                         Imrgb.getGreen()(i+1,j+1),
                         Imrgb.getBlue()(i+1,j+1));
            img.setPixel(i,j,color.rgb());
        }

    return img;
}

QImage ImageProcessing::bitMap2Image(const LinAlg::Matrix<int> &imgBitMap)
{
    QImage img(imgBitMap.getNumberOfRows(),imgBitMap.getNumberOfColumns(),QImage::Format_RGB32);

    for(unsigned i = 0; i < imgBitMap.getNumberOfRows(); ++i)
        for(unsigned j = 0; j < imgBitMap.getNumberOfColumns(); ++j)
            img.setPixel(i,j,QColor(imgBitMap(i+1,j+1),imgBitMap(i+1,j+1),imgBitMap(i+1,j+1)).rgb());

    return img;
}

ImageProcessing::RGBImage ImageProcessing::subtraction(RGBImage &lhs, RGBImage &rhs)
{
    ImageProcessing::RGBImage rgbImg(lhs.getRed()-rhs.getRed(),
                                     lhs.getGreen()-rhs.getGreen(),
                                     lhs.getBlue()-rhs.getBlue());

    return rgbImg;
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
                bitMap(i,j) = 255;
        }

    return bitMap;
}