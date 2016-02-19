#include "negative_image.h"

/** Redeclation of the constructor */
NegativeImage::NegativeImage(PNM* img) :
    Transformation(img)
{
}

NegativeImage::NegativeImage(PNM* img, ImageViewer* iv) :
    Transformation(img, iv)
{
}

/** /virtual/
  * Returns a inverted image (negative) of the image given in the constructor
  */
PNM* NegativeImage::transform()
{
    // Getting the dimensions
    int width  = image->width();
    int height = image->height();

    PNM* newImage = new PNM(width, height, image->format());

    if (image->format() == QImage::Format_Mono)
    {
        // Iterate over image space
        for (int x=0; x<width; x++)
            for (int y=0; y<height; y++)
            {
                QColor color = QColor::fromRgb(image->pixel(x,y)); // Getting the pixel(x,y) value

                newImage->setPixel(x,y, color == Qt::white ? Qt::color0 : Qt::color1);
            }
    }
    else if (image->format() == QImage::Format_Indexed8)
    {
        // Iterate over image space
        for (int x=0; x<width; x++)
            for (int y=0; y<height; y++)
            {
                QRgb pixel = image->pixel(x,y); // Getting the pixel(x,y) value

                int v = qGray(pixel);    // Get the 0-255 value of the L channel
                v = PIXEL_VAL_MAX - v;

                newImage->setPixel(x,y, v);
            }
    }
    else //if (image->format() == QImage::Format_RGB32)
    {
        // Iterate over image space
        for (int x=0; x<width; x++)
            for (int y=0; y<height; y++)
            {
                QRgb pixel = image->pixel(x,y); // Getting the pixel(x,y) value

                int r = qRed(pixel);    // Get the 0-255 value of the R channel
                int g = qGreen(pixel);  // Get the 0-255 value of the G channel
                int b = qBlue(pixel);   // Get the 0-255 value of the B channel
                r = PIXEL_VAL_MAX - r;
                g = PIXEL_VAL_MAX - g;
                b = PIXEL_VAL_MAX - b;
                QColor newPixel = QColor(r,g,b);
                newImage->setPixel(x,y, newPixel.rgb());
            }
    }

    return newImage;
}
