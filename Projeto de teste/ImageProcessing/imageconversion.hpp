#include "ImageProcessing/imageconversion.h"

template <class Type>
QImage ImageConversion::RGBImage2QImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    return ImageConversion::SetPixel<Type>(rgbImg.getRed(),rgbImg.getGreen(),rgbImg.getBlue());
}

template <class Type>
QImage ImageConversion::GrayImage2QImage(const ImageProcessing::GrayImage<Type> &grayImg)
{
    LinAlg::Matrix<Type> gray = grayImg.getGray();
    return ImageConversion::SetPixel<Type>(gray,gray,gray);
}

template <class Type>
QImage ImageConversion::Bitmap2QImage(const LinAlg::Matrix<Type> bitmap)
{
    return ImageConversion::SetPixel<Type>(bitmap, bitmap, bitmap);
}

template <class Type>
QImage ImageConversion::RedImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> g = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());
    LinAlg::Matrix<Type> b = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());

    return ImageConversion::SetPixel<Type>(rgbImg.getRed(),g,b);
}

template <class Type>
QImage ImageConversion::GreenImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> r = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());
    LinAlg::Matrix<Type> b = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());

    return ImageConversion::SetPixel<Type>(r,rgbImg.getGreen(),b);
}

template <class Type>
QImage ImageConversion::BlueImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> r = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());
    LinAlg::Matrix<Type> g = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());

    return ImageConversion::SetPixel<Type>(r,g,rgbImg.getBlue());
}

template <class Type>
QImage ImageConversion::SetPixel(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b)
{
    QImage ret(r.getNumberOfRows(),r.getNumberOfColumns(),QImage::Format_RGB32);

    for(unsigned i = 0; i < r.getNumberOfRows(); ++i)
        for(unsigned j = 0; j < r.getNumberOfColumns(); ++j)
            ret.setPixel(i,j,QColor(r(i+1,j+1),g(i+1,j+1),b(i+1,j+1)).rgb());

    return ret;
}

template <class Type>
ImageProcessing::RGBImage<Type> ImageConversion::QImage2RGBImage(const QImage &img)
{
    LinAlg::Matrix<Type> r(img.width(),img.height()), g(img.width(),img.height()), b(img.width(),img.height());

    for(unsigned i = 0; i < img.width(); ++i)
            for(unsigned j = 0; j < img.height(); ++j){
                QColor color(img.pixel(i,j));
                r(i+1,j+1) = color.red();
                g(i+1,j+1) = color.green();
                b(i+1,j+1) = color.blue();
            }

    ImageProcessing::RGBImage<Type> ret(r,g,b);

    return ret;
}

template <class Type>
ImageProcessing::GrayImage<Type> ImageConversion::QImage2GrayImage(const QImage &img)
{
    LinAlg::Matrix<Type> gray(img.width(),img.height());
    for(unsigned i = 0; i < img.width(); ++i)
            for(unsigned j = 0; j < img.height(); ++j){
                QColor color(img.pixel(i,j));
                gray(i+1,j+1) = qGray(color.red(),color.green(),color.blue());
            }

    ImageProcessing::GrayImage<Type> ret(gray);
    return ret;
}

template <class Type>
ImageProcessing::GrayImage<Type> ImageConversion::RGBImage2GrayImage(const ImageProcessing::RGBImage<Type> &rgbimg)
{
    LinAlg::Matrix<Type> gray(rgbimg.getWidth(), rgbimg.getHeight()),
                        r = rgbimg.getRed(),
                        g = rgbimg.getGreen(),
                        b = rgbimg.getBlue();

    for(unsigned i = 1; i <= gray.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= gray.getNumberOfColumns(); ++j)
            gray(i,j) = qGray(r(i,j),g(i,j),b(i,j));

    ImageProcessing::GrayImage<Type> ret(gray);
    return ret;
}
