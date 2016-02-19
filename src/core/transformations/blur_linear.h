#ifndef BLUR_LINEAR_H
#define BLUR_LINEAR_H

#include "convolution.h"

class BlurLinear : public Convolution
{
public:
    BlurLinear(PNM*);
    BlurLinear(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // BLUR_LINEAR_H
