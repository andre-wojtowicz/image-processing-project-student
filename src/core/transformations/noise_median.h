#ifndef NOISE_MEDIAN_H
#define NOISE_MEDIAN_H

#include "convolution.h"

class NoiseMedian : public Convolution
{
public:
    NoiseMedian(PNM*);
    NoiseMedian(PNM*, ImageViewer*);

    virtual PNM* transform();

private:
    int getMedian(int, int, Channel);
};

#endif // NOISE_MEDIAN_H
