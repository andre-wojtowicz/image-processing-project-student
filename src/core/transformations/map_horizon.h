#ifndef HORIZON_MAP_H
#define HORIZON_MAP_H

#include "transformation.h"

class MapHorizon : public Transformation
{
public:
    enum DIRECTION {NORTH, EAST, WEST, SOUTH};

    MapHorizon(PNM*);
    MapHorizon(PNM*, ImageViewer*);

    PNM* transform();
};

#endif // HORIZON_MAP_H
