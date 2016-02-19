#ifndef CORRECTION_H
#define CORRECTION_H

#include "transformation.h"

class Correction : public Transformation
{
public:
    Correction(PNM*);
    Correction(PNM*, ImageViewer*);

    virtual PNM* transform();

private:
    int LUT[PIXEL_VAL_MAX+1];
};

#endif // CORRECTION_H
