#include "Matrix.h"

class PoolLayer {

    public:
        PoolLayer(int stride, int filterSize, int depth, int padding, int inputWidth, int inputHeight);
        ~PoolLayer();
        Matrix* feedForward(Matrix *rawInput);
        Matrix* backPropagation(Matrix *dOut);

    private:
        int outputChannels{}, stride{}, filterSize{}, padding{}, inputChannels{}, inputWidth{}, inputHeight{};
        int *indexes{};
        void fillOutput(float *input, int offset, int size, Matrix *output);
};