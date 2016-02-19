#include "hough.h"

#include "conversion_grayscale.h"
#include "edge_laplacian.h"

Hough::Hough(PNM* img) :
    Transformation(img)
{
}

Hough::Hough(PNM* img, ImageViewer* super) :
    Transformation(img, super)
{
}

PNM* Hough::transform()
{   
    int thetaDensity = getParameter("theta_density").toInt();

    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return 0;
}
