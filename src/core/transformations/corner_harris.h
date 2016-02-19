#ifndef CORNER_HARRIS_H
#define CORNER_HARRIS_H

#include "convolution.h"

class CornerHarris : public Convolution
{
public:
    CornerHarris(PNM*);
    CornerHarris(PNM*, ImageViewer*);

    PNM* transform();
};

#endif // CORNER_HARRIS_H
