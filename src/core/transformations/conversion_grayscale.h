#ifndef CONVERSION_GRAYSCALE_H
#define CONVERSION_GRAYSCALE_H

#include "transformation.h"

class ConversionGrayscale : public Transformation
{
public:
    ConversionGrayscale(PNM*);
    ConversionGrayscale(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // CONVERSION_GRAYSCALE_H
