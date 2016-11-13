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
}
