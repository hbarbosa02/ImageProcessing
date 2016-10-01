# ImageProcessing
Biblioteca em C++ para processamento de imagens, criada como meta da matéria de visão computacional.

# Métodos criados até o momento

* Classe RGBImage
  * Construtores:
    * RGBImage();
    * RGBImage(const QImage &image);
    * RGBImage(LinAlg::Matrix<int> r,LinAlg::Matrix<int> g,LinAlg::Matrix<int> b);
  * Métodos publicos:
    * getRed();
    * getGreen();
    * getBlue();
    * getGray();
    * redImage();
    * greenImage();
    * blueImage();
    * grayImage();
    * Height();
    * Width();
    
* namespace ImageProcessing
  * rgbImg2QImage(RGBImage &Imrgb);
  * bitMap2Image(const LinAlg::Matrix<int> &imgBitMap);
  * subtraction(RGBImage &lhs, RGBImage &rhs);
  * bitMap(RGBImage &rgbImg);
  * Histogram(const QImage &img);
