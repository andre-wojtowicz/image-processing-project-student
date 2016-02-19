#ifndef MORPHOLOGICALOPERATOR_H
#define MORPHOLOGICALOPERATOR_H

#include "transformation.h"

class MorphologicalOperator : public Transformation
{
public:
    enum SE { Square, Cross, XCross, VLine, HLine };
    enum Selector { Minimum, Maximum };

    MorphologicalOperator(PNM*);
    MorphologicalOperator(PNM*, ImageViewer*);

    math::matrix<bool> getSE(int, SE);
    PNM* transform();
protected:

    virtual const int morph(math::matrix<float>, math::matrix<bool>);
    math::matrix<bool> seSquare(int);
    math::matrix<bool> seCross(int);

    // am to lazy to implement now
    math::matrix<bool> seXCross(int);
    math::matrix<bool> seVLine(int);
    math::matrix<bool> seHLine(int);
};

#endif // MORPHOLOGICALOPERATOR_H
