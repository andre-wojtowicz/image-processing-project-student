#ifndef BIN_NIBLACK_H
#define BIN_NIBLACK_H

#include "transformation.h"

class BinarizationNiblack : public Transformation
{
public:
    BinarizationNiblack(PNM*);
    BinarizationNiblack(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // BIN_NIBLACK_H
