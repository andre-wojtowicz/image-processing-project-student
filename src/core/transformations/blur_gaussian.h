#ifndef BLUR_GAUSSIAN_H
#define BLUR_GAUSSIAN_H

#include "convolution.h"

class BlurGaussian : public Convolution
{
public:
    BlurGaussian(PNM*);
    BlurGaussian(PNM*, ImageViewer*);

    virtual PNM* transform();
    virtual math::matrix<float> getMask(int, Mode);
    static float getGauss(int, int, float);

private:
    int    radius;
    double sigma;
};

#endif // BLUR_GAUSSIAN_H
