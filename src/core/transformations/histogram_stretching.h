#ifndef HISTOGRAM_STRETCHING_H
#define HISTOGRAM_STRETCHING_H

#include "transformation.h"

class HistogramStretching : public Transformation
{
public:
    HistogramStretching(PNM*);
    HistogramStretching(PNM*, ImageViewer* iv);

    virtual PNM* transform();
};

#endif // HISTOGRAM_STRETCHING_H
