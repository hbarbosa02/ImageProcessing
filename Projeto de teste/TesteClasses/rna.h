#ifndef RNA_H
#define RNA_H

#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/neuron.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace NeuralNetworkHandler {
    template <class Type>
    class RNA
    {
    public:
        ~RNA();
        RNA();
        RNA(unsigned inputLayer,
            unsigned hiddenLayer,
            unsigned numOutput);

        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> input, ModelHandler::Model<Type> *model);
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> input, NeuralNetworkHandler::Neuron<Type> *neuron);

    private:
        LinAlg::Matrix<Type> inLayer,hiLayer,ouLayer,inWeight,hiWeight,ouWeight;

        ModelHandler::Model<Type>* model;
        NeuralNetworkHandler::Neuron<Type>* neuron;
    };
}
#include"TesteClasses/rna.hpp"
#endif // RNA_H
