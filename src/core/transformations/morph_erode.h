#ifndef MORPH_ERODE_H
#define MORPH_ERODE_H

#include "morphological_operator.h"

class MorphErode : public MorphologicalOperator
{
public:
    MorphErode(PNM*);
    MorphErode(PNM*, ImageViewer*);

    const int morph(math::matrix<float>, math::matrix<bool>);
};

#endif // MORPH_ERODE_H
