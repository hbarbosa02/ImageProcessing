#include "ImageProcessing/imageprocessing.h"

template <typename Type>
int ImageProcessing::GetColorPixel(const Type &r,const Type &g, const Type &b)
{
    return QColor(r,g,b).value();
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::checkValue(const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),mat.getNumberOfColumns());

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
        {
            if(mat(i,j) > 255)
                ret(i,j) = 255;
            else if(mat(i,j) < 0)
                ret(i,j) = 0;
            else
                ret(i,j) = mat(i,j);
        }

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::GetColorPixel(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b)
{
    LinAlg::Matrix<Type> ret(r.getNumberOfRows(),r.getNumberOfColumns());

    for(unsigned i = 1; i <= r.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= r.getNumberOfColumns(); ++j)
            ret(i,j) = QColor(r(i,j),g(i,j),b(i,j)).value();

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::Histogram(const LinAlg::Matrix<Type> &img)
{
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(1,256);

    for(unsigned i = 1; i <= img.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= img.getNumberOfColumns(); ++j)
        {
            int k = img(i,j);
            ret(1,k) += 1;
        }

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::ApplyingMask(const LinAlg::Matrix<Type> &mat, const LinAlg::Matrix<Type> &mask)
{
    LinAlg::Matrix<Type> ret = LinAlg::Zeros<Type>(mat.getNumberOfRows(),mat.getNumberOfColumns());
    LinAlg::Matrix<Type> aux;

    unsigned rowSum = (int)mask.getNumberOfRows()/2;
    unsigned colSum = (int)mask.getNumberOfColumns()/2;
    unsigned rowLim = ret.getNumberOfRows() - mask.getNumberOfRows() +1;
    unsigned colLim = ret.getNumberOfColumns() - mask.getNumberOfColumns() +1;

    for(unsigned i = 1; i <= rowLim; ++i){
        for(unsigned j = 1; j <= colLim; ++j){
            aux = mat(from(i+mask.getNumberOfRows()-1)-->(i),from(j+mask.getNumberOfColumns()-1)-->(j));
            ret(i+rowSum,j+colSum) = LinAlg::sum(LinAlg::multPointToPoint(aux,mask));
        }
    }
    return ret;
}

template<typename Type>
LinAlg::Matrix<Type> ImageProcessing::BitMap(const LinAlg::Matrix<Type> &mat, const unsigned &limiar)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(), mat.getNumberOfColumns());

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
        {
            if(mat(i,j) > limiar)
                ret(i,j) = 255;
            else
                ret(i,j) = 0;
        }
    return ret;
}

template<typename Type>
LinAlg::Matrix<Type> ImageProcessing::ColorInversion(const LinAlg::Matrix<Type> &mat)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(), mat.getNumberOfColumns());
    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
            ret(i,j) = 255 - mat(i,j);

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::Rotation(const LinAlg::Matrix<Type> &mat, const double &angle)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(),mat.getNumberOfColumns());
    LinAlg::Matrix<double> p1(2,1), p2(2,1), pos;
    LinAlg::Matrix<double> rot(2,2);

    double ang  = angle * M_PI/180;

    rot(1,1) = cos(ang); rot(1,2) = sin(ang);
    rot(2,1) = -sin(ang); rot(2,2) = cos(ang);

    p2(1,1) = mat.getNumberOfColumns()/2;
    p2(2,1) = mat.getNumberOfRows()/2;

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j){
            p1(1,1) = i - p2(2,1);
            p1(2,1) = j - p2(1,1);

            pos = (rot *p1) + p2;

            if(pos(2,1)>0 && pos(2,1) <= mat.getNumberOfColumns() && pos(1,1)>0 && pos(1,1) <= mat.getNumberOfRows())
                ret(i,j) = mat(Type(pos(1,1)),Type(pos(2,1)));
        }

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::Scale(const LinAlg::Matrix<Type> &mat, const double &scale)
{
    LinAlg::Matrix<Type> ret;

    if(scale > 1)
        ret = LinAlg::Zeros<Type>((Type)ceil(mat.getNumberOfRows()*scale),(Type)ceil(mat.getNumberOfColumns()*scale));
    else
        ret = LinAlg::Zeros<Type>((Type)floor(mat.getNumberOfRows()*scale),(Type)floor(mat.getNumberOfColumns()*scale));

    for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
        for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
        {
            if(scale > 1)
                ret(i,j) = mat(ceil(i/scale),ceil(j/scale));
            else
                ret(i,j) = mat(floor(i/scale),floor(j/scale));
        }

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::Reflect(const LinAlg::Matrix<Type> &mat, bool flag)
{
    LinAlg::Matrix<Type> ret(mat.getNumberOfRows(), mat.getNumberOfColumns());

    if(flag){
        for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
            for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
                ret(i,j) = mat(i,ret.getNumberOfColumns()-j+1);
    } else {
        for(unsigned i = 1; i <= ret.getNumberOfRows(); ++i)
            for(unsigned j = 1; j <= ret.getNumberOfColumns(); ++j)
                ret(i,j) = mat(ret.getNumberOfRows()-i+1,j);
    }

    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::MediaFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask)
{
    if(sizeMask % 2 == 0){
        std::cout << "sizeMask deve ser impar" << std::endl;
        return mat;
    } else{
        LinAlg::Matrix<Type> ret = mat;
        LinAlg::Matrix<Type> aux;
        int n = sizeMask / 2;
        Type temp = 0;

        for(unsigned i = 1+n; i <= ret.getNumberOfRows()-n; ++i)
            for(unsigned j = 1+n; j <= ret.getNumberOfColumns()-n; ++j){
                aux = mat(from(i-n)-->(i+n),from(j-n)-->(j+n));
                temp = LinAlg::sum(aux)/(sizeMask*sizeMask);
                ret(i,j) = temp;
            }
        return ret;
    }
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::MedianFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask)
{
    LinAlg::Matrix<Type> ret = mat;
    LinAlg::Matrix<Type> aux;
    int n = sizeMask / 2, g = (sizeMask*sizeMask)/2;

    Type temp = 0;

    for(unsigned i = 1+n; i <= ret.getNumberOfRows()-n; ++i)
        for(unsigned j = 1+n; j <= ret.getNumberOfColumns()-n; ++j){
            aux = mat(from(i-n)-->(i+n),from(j-n)-->(j+n));
            aux = LinAlg::selectionSort<Type>(aux);
            if(sizeMask % 2 == 0)
                temp = (aux(1,g) + aux(1,g+1))/2;
            else
                temp = aux(1,g);

            ret(i,j) = temp;
        }
    return ret;
}

template <typename Type>
LinAlg::Matrix<Type> ImageProcessing::SelfReinforcementFilter(const LinAlg::Matrix<Type> &mat, const int &sizeMask, const double &a)
{
    if(sizeMask % 2 == 0){
        std::cout << "sizeMask deve ser impar" << std::endl;
        return mat;
    } else{
        LinAlg::Matrix<Type> ret = mat;
        LinAlg::Matrix<Type> aux, filtro;
        filtro = LinAlg::Ones<Type>(sizeMask,sizeMask);
        int n = sizeMask / 2;
        Type temp = 0;

        for(unsigned i = 1+n; i <= ret.getNumberOfRows()-n; ++i)
            for(unsigned j = 1+n; j <= ret.getNumberOfColumns()-n; ++j){
                aux = mat(from(i-n)-->(i+n),from(j-n)-->(j+n));
                temp = LinAlg::sum<Type>(LinAlg::multPointToPoint<Type>(aux,filtro));
                ret(i,j) = temp;
            }
        ret = LinAlg::abs<Type>(a*mat-ret);
        return ImageProcessing::checkValue<Type>(ret);
    }
}
