#ifndef EDGE_LAPLACE_GAUSS_H
#define EDGE_LAPLACE_GAUSS_H

#include "convolution.h"

class EdgeLaplaceOfGauss : public Convolution
{
public:
    EdgeLaplaceOfGauss(PNM*);
    EdgeLaplaceOfGauss(PNM*, ImageViewer*);

    virtual math::matrix<float> getMask(int, Mode);

    static float getLoG(int, int, float);
    int getSize();

private:
    int size;
};

#endif // EDGE_LAPLACE_GAUSS_H
