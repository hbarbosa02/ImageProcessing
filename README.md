# ImageProcessing
Biblioteca em C++ para processamento de imagens, criada como meta da matéria de visão computacional.

# Métodos criados até o momento

* Classe RGBImage:
  * Construtores:
    * RGBImage(); //ok
    * RGBImage(const QImage &image); //ok
    * RGBImage(LinAlg::Matrix<int> r,LinAlg::Matrix<int> g,LinAlg::Matrix<int> b); //ok
  * Métodos publicos:
    * getRed() const; //ok
    * getGreen() const; //ok
    * getBlue() const; //ok
    * getGray() const; //ok
    * Height() const; //ok
    * Width() const; //ok
    * operator= (const ImageProcessing::RGBImage& OtherRGBImage); //não foi testada
    * operator+= (const int& rhs); //não foi testada
    * operator-= (const int& rhs); //não foi testada
    * operator*= (const int& rhs); //não foi testada
    * operator/= (const int& rhs); //não foi testada
    
* namespace ImageProcessing:
  * operator+  (ImageProcessing::RGBImage lhs, const int& rhs); //não foi testada
  * operator+  (const int& lhs, ImageProcessing::RGBImage rhs); //não foi testada
  * operator-  (ImageProcessing::RGBImage lhs, const int& rhs); //não foi testada
  * operator-  (const int& lhs, ImageProcessing::RGBImage rhs); //não foi testada
  * operator*  (ImageProcessing::RGBImage lhs, const int& rhs); //não foi testada
  * operator*  (const int& lhs, ImageProcessing::RGBImage rhs); //não foi testada
  * operator/  (ImageProcessing::RGBImage lhs, const int& rhs); //não foi testada
  * operator/  (const int& lhs, ImageProcessing::RGBImage rhs); //não foi testada
  * redImage(RGBImage &Imrgb); //ok
  * greenImage(RGBImage &Imrgb); //ok
  * blueImage(RGBImage &Imrgb); //ok
  * grayImage(RGBImage &Imrgb); //ok
  * rgbImg2QImage(RGBImage &Imrgb); //ok
  * bitMap2Image(const LinAlg::Matrix<int> &imgBitMap); //ok
  * subtraction(RGBImage &lhs, RGBImage &rhs); //não foi testada
  * bitMap(RGBImage &rgbImg); //ok
  * Histogram(const QImage &img); //não foi testada
  
# Problemas encontrados com a classe
A classe aparente apresenta problemas quando é usado ponteiros da classe, apresenta um erro de multiplas definições, a unica forma de utilização até agora é criando váriaveis da classe dentro do documento.cpp do projeto.
