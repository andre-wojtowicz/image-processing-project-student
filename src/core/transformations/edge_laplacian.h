#ifndef EDGE_LAPLACIAN_H
#define EDGE_LAPLACIAN_H

#include "convolution.h"

class EdgeLaplacian : public Convolution
{
public:
    EdgeLaplacian(PNM*);
    EdgeLaplacian(PNM*, ImageViewer*);

    virtual math::matrix<float> getMask(int, Mode);
};

#endif // EDGE_LAPLACIAN_H
