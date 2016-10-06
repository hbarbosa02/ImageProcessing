#include "rgbimage.h"

ImageProcessing::RGBImage::RGBImage(QImage image)
{
    this->height = image.height();
    this->width = image.width();
    this->a = 255;

    this->blue = LinAlg::Zeros<int>(this->height,this->width);
    this->green = LinAlg::Zeros<int>(this->height,this->width);
    this->red = LinAlg::Zeros<int>(this->height,this->width);
    this->gray = LinAlg::Zeros<int>(this->height,this->width);

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

ImageProcessing::RGBImage& ImageProcessing::RGBImage::operator=  (const ImageProcessing::RGBImage& OtherRGBImage)
{
    this->red = OtherRGBImage.getRed();
    this->green = OtherRGBImage.getGreen();
    this->blue = OtherRGBImage.getBlue();
    this->gray = OtherRGBImage.getGray();
    this->a = 255;

    this->width = OtherRGBImage.Width();
    this->height = OtherRGBImage.Height();

    return *this;
}

ImageProcessing::RGBImage& ImageProcessing::RGBImage::operator+=  (const int& rhs)
{
    this->red += rhs;
    this->green += rhs;
    this->blue += rhs;
    this->gray += rhs;

    return *this;
}

ImageProcessing::RGBImage& ImageProcessing::RGBImage::operator-=  (const int& rhs)
{
    this->red -= rhs;
    this->green -= rhs;
    this->blue -= rhs;
    this->gray -= rhs;

    return *this;
}

ImageProcessing::RGBImage& ImageProcessing::RGBImage::operator*=  (const int& rhs)
{
    this->red *= rhs;
    this->green *= rhs;
    this->blue *= rhs;
    this->gray *= rhs;

    return *this;
}

ImageProcessing::RGBImage& ImageProcessing::RGBImage::operator/=  (const int& rhs)
{
    this->red /= rhs;
    this->green /= rhs;
    this->blue /= rhs;
    this->gray /= rhs;

    return *this;
}
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------

QImage ImageProcessing::redImage(RGBImage Imrgb)
{
    QImage img(Imrgb.Height(),Imrgb.Width(),QImage::Format_RGB32);

    for(unsigned i = 0; i < Imrgb.Height(); ++i)
        for(unsigned j = 0; j < Imrgb.Width(); ++j)
            img.setPixel(i,j,QColor(Imrgb.getRed()(i+1,j+1),0,0).rgb());

    return img;
}

QImage ImageProcessing::greenImage(RGBImage Imrgb)
{
    QImage img(Imrgb.Height(),Imrgb.Width(),QImage::Format_RGB32);

    for(unsigned i = 0; i < Imrgb.Height(); ++i)
        for(unsigned j = 0; j < Imrgb.Width(); ++j)
            img.setPixel(i,j,QColor(Imrgb.getGreen()(i+1,j+1),0,0).rgb());

    return img;
}

QImage ImageProcessing::blueImage(RGBImage Imrgb)
{
    QImage img(Imrgb.Height(),Imrgb.Width(),QImage::Format_RGB32);

    for(unsigned i = 0; i < Imrgb.Height(); ++i)
        for(unsigned j = 0; j < Imrgb.Width(); ++j)
            img.setPixel(i,j,QColor(Imrgb.getBlue()(i+1,j+1),0,0).rgb());

    return img;
}

QImage ImageProcessing::grayImage(RGBImage Imrgb)
{
    QImage img(Imrgb.Height(),Imrgb.Width(),QImage::Format_RGB32);

    for(unsigned i = 0; i < Imrgb.Height(); ++i)
        for(unsigned j = 0; j < Imrgb.Width(); ++j)
            img.setPixel(i,j,QColor(Imrgb.getGray()(i+1,j+1),
                                    Imrgb.getGray()(i+1,j+1),
                                    Imrgb.getGray()(i+1,j+1)).rgb());

    return img;
}
QImage ImageProcessing::rgbImg2QImage(RGBImage Imrgb)
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

QImage ImageProcessing::bitMap2Image(LinAlg::Matrix<int> imgBitMap)
{
    QImage img(imgBitMap.getNumberOfRows(),imgBitMap.getNumberOfColumns(),QImage::Format_RGB32);

    for(unsigned i = 0; i < imgBitMap.getNumberOfRows(); ++i)
        for(unsigned j = 0; j < imgBitMap.getNumberOfColumns(); ++j)
            img.setPixel(i,j,QColor(imgBitMap(i+1,j+1),
                                    imgBitMap(i+1,j+1),
                                    imgBitMap(i+1,j+1)).rgb());

    return img;
}

LinAlg::Matrix<int> ImageProcessing::bitMap(ImageProcessing::RGBImage rgbImg)
{
    LinAlg::Matrix<int> bitMap = rgbImg.getGray();

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

LinAlg::Matrix<int> ImageProcessing::Histogram(ImageProcessing::RGBImage img)
{
    LinAlg::Matrix<int> histogram = LinAlg::Zeros<int>(1,256);

    for(unsigned i = 1; i <= img.Height(); ++i)
        for(unsigned j = 1; j <= img.Width(); ++j)
        {
            int k = img.getGray()(i,j);
            histogram(k,1) += 1;
        }

    return histogram;
}
