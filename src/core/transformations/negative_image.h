#ifndef NEGATIVEIMAGE_H
#define NEGATIVEIMAGE_H

#include "transformation.h"

class NegativeImage : public Transformation
{
public:
    NegativeImage(PNM*);
    NegativeImage(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // NEGATIVEIMAGE_H

