#ifndef BIN_ITERBIMODAL_H
#define BIN_ITERBIMODAL_H

#include "transformation.h"

class BinarizationIterBimodal : public Transformation
{
public:
    BinarizationIterBimodal(PNM*);
    BinarizationIterBimodal(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // BIN_ITERBIMODAL_H
