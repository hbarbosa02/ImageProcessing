# ImageProcessing
Biblioteca em C++ para processamento de imagens, criada como trabalho de conclusão da matéria de visão computacional. Foi pensanda para ser semelhante as funções do matlab, tentando minimizar a dificuldade da mudança de linguagem, ela está ligada a biblioteca "Sistema de Controle", além das ferramentas do QT (Qimage e Qcolor).

# Namespace ImagePRocessing
 * QImage RGBImage2QImage(const ImageProcessing::RGBImage<Type> &rgbImg)
 * QImage GrayImage2QImage(const ImageProcessing::GrayImage<Type> &grayImg)
 * QImage Bitmap2QImage(const LinAlg::Matrix<Type> bitmap)
 * QImage RedImage(const ImageProcessing::RGBImage<Type> &rgbImg)
 * QImage GreenImage(const ImageProcessing::RGBImage<Type> &rgbImg)
 * QImage BlueImage(const ImageProcessing::RGBImage<Type> &rgbImg)
 * QImage SetPixel(const LinAlg::Matrix<Type> &r,const LinAlg::Matrix<Type> &g,const LinAlg::Matrix<Type> &b)
 * ImageProcessing::RGBImage<Type> QImage2RGBImage(const QImage &img)
 * ImageProcessing::GrayImage<Type> QImage2GrayImage(const QImage &img)
 * ImageProcessing::GrayImage<Type> RGBImage2GrayImage(const ImageProcessing::RGBImage<Type> &rgbimg)
 * int GetColorPixel(const Type &r,const Type &g, const Type &b)
 * LinAlg::Matrix<int> GetColorPixel(const LinAlg::Matrix<Type> &r,const LinAlg::Matrix<Type> &g,const LinAlg::Matrix<Type> &b)
 * LinAlg::Matrix<Type> Histogram(const LinAlg::Matrix<Type> &img)
 * LinAlg::Matrix<Type> HistogramRGB(const ImageProcessing::RGBImage<Type> &rgbimg)
 * LinAlg::Matrix<Type> HistogramGray(const ImageProcessing::GrayImage<Type> &grayimg)
 * ImageProcessing::RGBImage<Type> Rotation(const ImageProcessing::RGBImage<Type> &rgbimg, const double &angle)
 * ImageProcessing::GrayImage<Type> Rotation(const ImageProcessing::GrayImage<Type> &grayimg, const double &angle)
 
# Classe RGBImage
 * RGBImage()
 * RGBImage(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b)
 * LinAlg::Matrix<Type> getRed()
 * LinAlg::Matrix<Type> getGreen()
 * LinAlg::Matrix<Type> getBlue()
 * LinAlg::Matrix<Type> getRGB()
 * unsigned getWidth()
 * unsigned getHeight()
 * ImageProcessing::RGBImage<Type>& operator =(const ImageProcessing::RGBImage<Type>& rgbImg)

# Classe GrayImage
 * GrayImage()
 * GrayImage(const LinAlg::Matrix<Type> &gray)
 * LinAlg::Matrix<Type> getGray()
 * unsigned getWidth()
 * unsigned getHeight()
 * ImageProcessing::GrayImage<Type>& operator= (const ImageProcessing::GrayImage<Type>& grayImg)

# Objetico
[...]
