#ifndef EDGE_ROBERTS_H
#define EDGE_ROBERTS_H

#include "edge_gradient.h"

class EdgeRoberts : public EdgeGradient
{
public:
    EdgeRoberts(PNM*);
    EdgeRoberts(PNM*, ImageViewer*);

private:
    virtual void prepareMatrices();
};

#endif // EDGE_ROBERTS_H
