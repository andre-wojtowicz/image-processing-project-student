#ifndef EDGE_GRADIENT_H
#define EDGE_GRADIENT_H

#include "convolution.h"

class EdgeGradient : public Convolution
{
public:
    EdgeGradient(PNM*);
    EdgeGradient(PNM*, ImageViewer*);

    virtual PNM* transform();

    PNM* verticalDetection();
    PNM* horizontalDetection();

protected:
    virtual void prepareMatrices() = 0;
    math::matrix<float> g_x,
                        g_y;
};

#endif // EDGE_GRADIENT_H
