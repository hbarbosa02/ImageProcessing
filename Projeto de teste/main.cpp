#include "mainwindow.h"
#include <QApplication>
#include "TesteClasses/rna.h"
#include "SistemasdeControle/headers/modelLibs/neuron.h"
#include "SistemasdeControle/headers/modelLibs/transferfunction.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

//    NeuralNetworkHandler::RNA<double> rna(4,10,4);
//    NeuralNetworkHandler::Neuron<double> n("Gaussian",0.3,0,5);

//    ModelHandler::TransferFunction<double> tf("1","1,2,1,1");

//    LinAlg::Matrix<double> input = "1;1;1;1";
//    LinAlg::Matrix<double> weight = "1;1;1;1";

//    std::cout << ~input * (weight) << std::endl;
//    std::cout << rna.sim(input, &tf) << std::endl;


//    LinAlg::Matrix<double> A = "1,1;1,1";
//    LinAlg::Matrix<double> B = "2,2;2,2";

//    LinAlg::Matrix<double> img = "1,1,1,1,1,1,1,1,1,1,1;"
//                                 "2,1,1,1,1,1,1,1,1,1,2;"
//                                 "2,1,1,1,1,1,1,1,1,1,2;"
//                                 "2,1,1,1,1,1,1,1,1,1,2;"
//                                 "2,1,1,1,1,1,1,1,1,1,2;"
//                                 "2,1,1,1,1,1,1,1,1,1,2;"
//                                 "1,1,1,1,1,1,1,1,1,1,1";

//    LinAlg::Matrix<double> mask = "0,1,0,1,0;"
//                                  "1,0,1,0,1;"
//                                  "1,0,1,0,1";


//    std::cout << LinAlg::multPointToPoint(A,B) << std::endl;
//    std::cout << LinAlg::sum(A) << std::endl;
//    std::cout << LinAlg::applyingMask(img,mask) << std::endl;

    return 0;
}
