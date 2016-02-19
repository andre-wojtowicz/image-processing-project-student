#ifndef BIN_GRADIENT_H
#define BIN_GRADIENT_H

#include "transformation.h"

class BinarizationGradient : public Transformation
{
public:
    BinarizationGradient(PNM*);
    BinarizationGradient(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // BIN_GRADIENT_H
