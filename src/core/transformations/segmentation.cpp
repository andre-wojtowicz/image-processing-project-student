#include "segmentation.h"

#include "conversion_grayscale.h"
#include "blur_gaussian.h"

#include <queue>

Segmentation::Segmentation(PNM* img) :
    Transformation(img)
{
}

Segmentation::Segmentation(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

#define INIT -1
#define MASK -2
#define WSHED 0

QPoint* Segmentation::neighbourhood(QPoint p)
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return new QPoint();
}

PNM* Segmentation::transform()
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return 0;
}
