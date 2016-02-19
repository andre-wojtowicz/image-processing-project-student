#ifndef HOUGH_LINES_H
#define HOUGH_LINES_H

#include "transformation.h"

class HoughLines : public Transformation
{
public:
    explicit HoughLines(PNM*);
    explicit HoughLines(PNM*, ImageViewer*);

    virtual PNM* transform();
};

#endif // HOUGH_LINES_H
