//
// Created by vmachado on 2/11/20.
//

#ifndef NNCPP_EXEC_NEURALNET_H
#define NNCPP_EXEC_NEURALNET_H

#include "Layer.h"
#include <ctime>
#include <fstream>
#include <iostream>

class NeuralNet {

public:
    NeuralNet(int featuresDimension, int outputDimension, int additionalHiddenLayers, int layersDimension,
              int batchSize);

    explicit NeuralNet(const char *path);

    void saveState(const char *path);

    void train(double **dataSet, int *labels, int samples, int epochs);

    Matrix *forwardStep(Matrix *batch, bool validation);

private:
    std::vector<Layer*> layers;
    double lambdaReg = 1e-3;
    double learningRate = 0.01;
    int featuresDimension{};
    int outputDimension{};
    int additionalHiddenLayers{};
    int layersDimension{};
    int batchSize{};

    static Matrix *getCorrectProb(Matrix *prob, const int *labels);

    static Matrix *getProbDerivative(Matrix *prob, const int *batchLabels);

    static Matrix *getReLUDerivative(Matrix *W, Matrix *W1);

    static double getDataLoss(Matrix *prob, int n);

    double getRegulationLoss();

    void shuffleDataFisherYates(double **data, int *labels, int samples);

    static Matrix *getBatchNormDerivative(Matrix *dOut, Layer *layer);

    void backPropagationStep(Matrix *prob, Matrix *batch, int *labels);
};


#endif //NNCPP_EXEC_NEURALNET_H