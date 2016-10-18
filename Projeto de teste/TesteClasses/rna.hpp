#include "rna.h"

template <class Type>
NeuralNetworkHandler::RNA<Type>::~RNA()
{

}

template <class Type>
NeuralNetworkHandler::RNA<Type>::RNA()
{

}

template <class Type>
NeuralNetworkHandler::RNA<Type>::RNA(unsigned numInput, unsigned hiddenLayer, unsigned numOutput)
{
    this->inLayer = LinAlg::Zeros<Type>(numInput,1);
    this->hiLayer = LinAlg::Zeros<Type>(hiddenLayer,1);
    this->ouLayer = LinAlg::Zeros<Type>(numOutput,1);

    this->inWeight = LinAlg::Random<Type>(numInput,1);
    this->hiWeight = LinAlg::Random<Type>(this->inLayer.getNumberOfRows(),this->hiLayer.getNumberOfRows());
    this->ouWeight = LinAlg::Random<Type>(this->hiLayer.getNumberOfRows(),this->ouLayer.getNumberOfRows());
}

template <class Type>
LinAlg::Matrix<Type> NeuralNetworkHandler::RNA<Type>::sim(LinAlg::Matrix<Type> input, ModelHandler::Model<Type> *model)
{
    if(input.getNumberOfRows() != this->inLayer.getNumberOfRows()){
        std::cout << "Numero de variaveis e de entradas sao diferentes!" << std::endl;
        return this->ouLayer;
    }

    this->model = model;
    LinAlg::Matrix<Type> Yi(this->inLayer.getNumberOfRows(),1);
    LinAlg::Matrix<Type> Yh(this->hiLayer.getNumberOfRows(),1);

    for(unsigned i = 1; i <= this->inLayer.getNumberOfRows(); ++i)
        Yi(i,1) = this->model->sim(input(i,1)*this->inWeight(i,1));

    return Yi;
}


template <class Type>
LinAlg::Matrix<Type> NeuralNetworkHandler::RNA<Type>::sim(LinAlg::Matrix<Type> input, NeuralNetworkHandler::Neuron<Type> *neuron)
{
    if(input.getNumberOfRows() != this->inLayer.getNumberOfRows()){
        std::cout << "Numero de neuronios e de entradas são diferentes!" << std::endl;
        return this->ouLayer;
    }

    this->neuron = neuron;
    LinAlg::Matrix<Type> Yi(this->inLayer.getNumberOfRows(),1);
    LinAlg::Matrix<Type> Yh(this->hiLayer.getNumberOfRows(),1);

    for(unsigned i = 1; i <= this->inLayer.getNumberOfRows(); ++i)
        Yi(i,1) = this->neuron->sim(input(i,1),this->inWeight(i,1));

    for(unsigned j = 1; j <= this->hiLayer.getNumberOfRows(); ++j)
        Yh(j,1) = this->neuron->sim(Yi,this->hiWeight.GetColumn(j));

    for(unsigned k = 1; k <= this->ouLayer.getNumberOfRows(); ++k)
        this->ouLayer(k,1) = this->neuron->sim(Yh,this->ouWeight.GetColumn(k));

    return this->ouLayer;
}
