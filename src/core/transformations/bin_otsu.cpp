#include "bin_otsu.h"

#include "histogram_equalization.h"
#include "../histogram.h"

BinarizationOtsu::BinarizationOtsu(PNM* img) :
    Transformation(img)
{
}

BinarizationOtsu::BinarizationOtsu(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

PNM* BinarizationOtsu::transform()
{
    int width = image->width();
    int height = image->height();

    PNM* newImage = new PNM(width, height, QImage::Format_Mono);

    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return newImage;
}

