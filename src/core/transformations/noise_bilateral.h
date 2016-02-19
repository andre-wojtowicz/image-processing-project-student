#ifndef NOISE_BILATERAL_H
#define NOISE_BILATERAL_H

#include "convolution.h"

class NoiseBilateral : public Convolution
{
public:
    NoiseBilateral(PNM*);
    NoiseBilateral(PNM*, ImageViewer*);

    virtual PNM* transform();

private:
    int   calcVal(int, int, Channel);
    float colorCloseness(int, int);
    float spatialCloseness(QPoint, QPoint);

    int sigma_d;
    int sigma_r;
    int radius;
};

#endif // NOISE_BILATERAL_H
