#ifndef TEXTURE_NORMAL_H
#define TEXTURE_NORMAL_H

#include "convolution.h"

class MapNormal : public Convolution
{
public:
    MapNormal(PNM*);
    MapNormal(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // TEXTURE_NORMAL_H
