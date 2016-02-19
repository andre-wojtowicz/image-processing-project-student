#ifndef HOUGH_H
#define HOUGH_H

#include "transformation.h"

class Hough : public Transformation
{
public:
    explicit Hough(PNM*);
    explicit Hough(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // HOUGH_H
