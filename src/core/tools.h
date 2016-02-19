#ifndef TOOLS_H
#define TOOLS_H

#include <QImage>
#include <QObject>

class ImageViewer;

class Tools : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ImageViewer* imageViewer READ getViewer WRITE setViewer)
public:
    explicit Tools(ImageViewer*, QObject *parent = 0);

    ImageViewer* getViewer();
    void         setViewer(ImageViewer*);
    bool         SupportedImageFormat(ImageViewer*, QList<QImage::Format>);

public slots:

    // lab. 1

    void negativeImage();
    void convertToGrayScale();
    void correctBrightnessContrastGamma();

    // lab. 2

    void histogramEqualize();
    void histogramShow();
    void histogramStretch();

    // lab. 3

    void blurGauss();
    void blurLinear();
    void blurUniform();

    // lab. 4

    void binGradient();
    void binIterBimodal();
    void binManual();
    void binNiblack();
    void binOtsu();

    // lab. 5

    void noiseMedian();
    void noiseBilateral();

    // lab. 6

    void morphErode();
    void morphDilate();
    void morphOpen();
    void morphClose();

    // lab. 7

    void edgeSobel();
    void edgePrewitt();
    void edgeRoberts();
    void edgeLaplacian();
    void edgeZero();

    // lab. 8

    void mapHeight();
    void mapNormal();
    void mapHorizon();

    // lab. 9

    void edgeCanny();

    // lab. 10

    void houghTransform();
    void houghLines();

    // lab. 11

    void cornerHarris();

    // lab. 12

    void houghRectangles();

    // lab. 13

    void segmentation();

    // display slots
    void rotate90();
    void rotate180();
    void rotate270();
    void zoom(float);

private:
    ImageViewer* m_iv;
};

#endif // TOOLS_H
