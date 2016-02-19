#ifndef MORPH_DILATE_H
#define MORPH_DILATE_H

#include "morphological_operator.h"

class MorphDilate : public MorphologicalOperator
{
public:
    MorphDilate(PNM*);
    MorphDilate(PNM*, ImageViewer*);

    const int morph(math::matrix<float>, math::matrix<bool>);
};

#endif // MORPH_DILATE_H
