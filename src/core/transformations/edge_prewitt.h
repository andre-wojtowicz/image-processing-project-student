#ifndef EDGE_PREWITT_H
#define EDGE_PREWITT_H

#include "edge_gradient.h"

class EdgePrewitt : public EdgeGradient
{
public:
    EdgePrewitt(PNM*);
    EdgePrewitt(PNM*, ImageViewer*);

private:
    virtual void prepareMatrices();
};

#endif // EDGE_PREWITT_H

