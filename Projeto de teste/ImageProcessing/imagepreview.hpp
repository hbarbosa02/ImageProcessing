#include "ImageProcessing/imagepreview.h"

template <class Type>
void imShow(const QImage &img,QLabel *label)
{
    label->setPixmap(QPixmap::fromImage(img));
}
