#include "noise_bilateral.h"

NoiseBilateral::NoiseBilateral(PNM* img) :
    Convolution(img)
{
}

NoiseBilateral::NoiseBilateral(PNM* img, ImageViewer* iv) :
    Convolution(img, iv)
{
}

PNM* NoiseBilateral::transform()
{
    int width  = image->width();
    int height = image->height();

    PNM* newImage = new PNM(width, height, image->format());

    sigma_d = getParameter("sigma_d").toInt();
    sigma_r = getParameter("sigma_r").toInt();
    radius = sigma_d;

    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return newImage;
}

int NoiseBilateral::calcVal(int x, int y, Channel channel)
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return 0;
}

float NoiseBilateral::colorCloseness(int val1, int val2)
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return 0;
}

float NoiseBilateral::spatialCloseness(QPoint point1, QPoint point2)
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";

    return 0;
}
