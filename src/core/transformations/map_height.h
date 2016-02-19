#ifndef MAP_HEIGHT_H
#define MAP_HEIGHT_H

#include "transformation.h"

class MapHeight : public Transformation
{
public:
    MapHeight(PNM*);
    MapHeight(PNM*, ImageViewer*);

    PNM* transform();
};

#endif // MAP_HEIGHT_H
