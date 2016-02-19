#include "hough_rectangles.h"

HoughRectangles::HoughRectangles(PNM* img) :
    Transformation(img)
{
}

HoughRectangles::HoughRectangles(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* HoughRectangles::transform()
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return 0;
}

