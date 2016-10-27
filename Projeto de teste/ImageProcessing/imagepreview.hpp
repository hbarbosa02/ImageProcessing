#include "ImageProcessing/imagepreview.h"

template <class Type>
void ImagePreview::imShow(QImage img,QLabel *label)
{
    label->setPixmap(QPixmap::fromImage(img));
}

template <typename Type>
void ImagePreview::imShow(ImageProcessing::GrayImage<Type> img,QLabel *label)
{
    label->setPixmap(QPixmap::fromImage(ImageConversion::GrayImage2QImage<Type>(img)));
}

template <typename Type>
void ImagePreview::imShow(ImageProcessing::RGBImage<Type> img,QLabel *label)
{
    label->setPixmap(QPixmap::fromImage(ImageConversion::RGBImage2QImage<Type>(img)));
}

template <typename Type>
void ImagePreview::imShow(LinAlg::Matrix<Type> img,QLabel *label)
{
    label->setPixmap(QPixmap::fromImage(ImageConversion::Bitmap2QImage<Type>(img)));
}
