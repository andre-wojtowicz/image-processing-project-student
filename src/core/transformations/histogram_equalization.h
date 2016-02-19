#ifndef HISTOGRAM_EQUALIZATION_H
#define HISTOGRAM_EQUALIZATION_H

#include "transformation.h"

class HistogramEqualization : public Transformation
{
public:
    HistogramEqualization(PNM*);
    HistogramEqualization(PNM*, ImageViewer*);

    virtual PNM* transform();
};


#endif // HISTOGRAM_EQUALIZATION_H
