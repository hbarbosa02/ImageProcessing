#ifndef IMAGEPREVIEW_H
#define IMAGEPREVIEW_H

#include "QImage"
#include "QLabel"
#include "QWidget"
#include "SistemasdeControle/headers/graphicLibs/plot.h"

namespace ImagePreview {

    template <class Type>
    void imShow(const QImage &img,QLabel *label);
}

#include "ImageProcessing/imagepreview.hpp"
#endif // IMAGEPREVIEW_H
