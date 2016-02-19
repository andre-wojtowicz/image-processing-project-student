#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#define _USE_MATH_DEFINES
#define PIXEL_VAL_MIN 0
#define PIXEL_VAL_MAX 255

#include "../pnm.h"
#include "../matrix/cmatrix"
#include "gui/imageviewer.h"

#include <QColor>
#include <QDebug>
#include <QThread>
#include <QVariant>
#include <QHash>

#include <cmath>

/**
  * Main abstract class providing an interface
  * for doing some computations on PNM images
  */
class Transformation : public QThread
{
    Q_OBJECT
public:
    enum Mode    {CyclicEdge, NullEdge, RepeatEdge, Normalize, Cut};
    enum Channel {RChannel, GChannel, BChannel, LChannel};

    explicit Transformation(PNM*);
    explicit Transformation(PNM*, ImageViewer*);
    ~Transformation();

    virtual PNM* transform();
    virtual void run();

    PNM*                 getImage();
    QRgb                 getPixel(int, int, Mode);
    math::matrix<float>  getWindow(int, int, int, Channel, Mode);
    QVariant             getParameter(QString);
    Transformation*      setParameter(QString, QVariant);
    ImageViewer*         getSupervisor();

signals:
    void resultReady(PNM*);
    void progress(int);
    void message(QString);

protected:
    QRgb getPixelCyclic(int, int);
    QRgb getPixelRepeat(int, int);
    QRgb getPixelNull(int, int);

    PNM*                      image;
    QHash<QString, QVariant>* parameters;
    ImageViewer*              supervisor;
};

#endif // TRANSFORMATION_H
