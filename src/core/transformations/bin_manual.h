#ifndef BIN_MANUAL_H
#define BIN_MANUAL_H

#include "transformation.h"

class BinarizationManual : public Transformation
{
public:
    BinarizationManual(PNM*);
    BinarizationManual(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // BIN_MANUAL_H
