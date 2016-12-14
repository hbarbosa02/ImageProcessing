#include "mainwindow.h"
#include <QApplication>

#include "TesteClasses/rna.h"
#include "SistemasdeControle/headers/modelLibs/neuron.h"
#include "SistemasdeControle/headers/modelLibs/transferfunction.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    LinAlg::Matrix<double> mat(3,3), mat1(3,3);
    mat(1, 1) = 1;
    mat(1, 2) = 0;
    mat(1, 3) = 0;
    mat(2, 1) = 0;
    mat(2, 2) = 1;
    mat(2, 3) = 0;
    mat(3, 1) = 0;
    mat(3, 2) = 0;
    mat(3, 3) = 1;

    mat1(1, 1) = 1;
    mat1(1, 2) = 2;
    mat1(1, 3) = 1;
    mat1(2, 1) = 1;
    mat1(2, 2) = 3;
    mat1(2, 3) = 1;
    mat1(3, 1) = 1;
    mat1(3, 2) = 1;
    mat1(3, 3) = 4;

    mat = mat/mat1;
    std::cout << mat(1,1);
    return 0;
}
