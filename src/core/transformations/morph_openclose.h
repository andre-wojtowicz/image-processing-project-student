#ifndef MORPHOPEN_H
#define MORPHOPEN_H

#include "morphological_operator.h"

class MorphOpenClose : public MorphologicalOperator
{
public:
    enum Type {Open, Close};

    MorphOpenClose(PNM*);
    MorphOpenClose(PNM*, ImageViewer*);

    PNM* transform();

private:
    PNM* erode(PNM*, int, SE);
    PNM* dilate(PNM*, int, SE);

    Type m_type;
};

#endif // MORPHOPEN_H
