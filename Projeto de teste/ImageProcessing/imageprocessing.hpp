#include "ImageProcessing/imageprocessing.h"

template <class Type>
QImage ImageProcessing::RGBImage2QImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    return ImageProcessing::SetPixel(rgbImg.getRed(),rgbImg.getGreen(),rgbImg.getBlue());
}

template <class Type>
QImage ImageProcessing::GrayImage2QImage(const ImageProcessing::GrayImage<Type> &grayImg)
{
    LinAlg::Matrix<Type> gray = grayImg.getGray();
    return ImageProcessing::SetPixel(gray,gray,gray);
}

template <class Type>
QImage ImageProcessing::Bitmap2QImage(const LinAlg::Matrix<Type> bitmap)
{
    return ImageProcessing::SetPixel(bitmap, bitmap, bitmap);
}

template <class Type>
QImage ImageProcessing::RedImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> g = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());
    LinAlg::Matrix<Type> b = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());

    return ImageProcessing::SetPixel<Type>(rgbImg.getRed(),g,b);
}

template <class Type>
QImage ImageProcessing::GreenImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> r = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());
    LinAlg::Matrix<Type> b = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());

    return ImageProcessing::SetPixel<Type>(r,rgbImg.getGreen(),b);
}

template <class Type>
QImage ImageProcessing::BlueImage(const ImageProcessing::RGBImage<Type> &rgbImg)
{
    LinAlg::Matrix<Type> r = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());
    LinAlg::Matrix<Type> g = LinAlg::Zeros<Type>(rgbImg.getWidth(), rgbImg.getHeight());

    return ImageProcessing::SetPixel<Type>(r,g,rgbImg.getBlue());
}

template <class Type>
QImage ImageProcessing::SetPixel(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b)
{
    QImage ret(r.getNumberOfRows(),r.getNumberOfColumns(),QImage::Format_RGB32);

    for(unsigned i = 0; i < r.getNumberOfRows(); ++i)
        for(unsigned j = 0; j < r.getNumberOfColumns(); ++j)
            ret.setPixel(i,j,QColor(r(i+1,j+1),g(i+1,j+1),b(i+1,j+1)).rgb());

    return ret;
}

template <class Type>
int ImageProcessing::GetPixel(const Type &r,const Type &g, const Type &b)
{
    return QColor(r,g,b).value();
}

template <class Type>
LinAlg::Matrix<Type> ImageProcessing::Histogram(const LinAlg::Matrix<Type> &img)
{
    LinAlg::Matrix<int> ret = LinAlg::Zeros<int>(1,256);

    for(unsigned i = 1; i <= img.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= img.getNumberOfColumns(); ++j)
        {
            int k = img(i,j);
            ret(1,k) += 1;
        }

    return ret;
}

