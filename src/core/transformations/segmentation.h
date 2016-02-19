#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include "transformation.h"

class Segmentation : public Transformation
{
public:
    explicit Segmentation(PNM*);
    explicit Segmentation(PNM*, ImageViewer*);

    virtual PNM* transform();

private:
    QPoint*  neighbourhood(QPoint);
};

#endif // SEGMENTATION_H
