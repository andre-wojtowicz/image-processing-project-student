#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "core/pnm.h"

#include <QWidget>
#include <QDebug>

class HistogramViewer;

namespace Ui {
class ImageViewer;
}

class ImageViewer : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName)
    Q_PROPERTY(QString path READ path)
    Q_PROPERTY(float zoom READ getZoom WRITE setZoom RESET resetZoom)

public:
    explicit ImageViewer(QWidget* parent = 0);
    ~ImageViewer();

    // Properties access:
    QString fileName();
    QString path();
    float   getZoom();
    void    setZoom(float);
    void    resetZoom();
    void    zoom(double);

    PNM*             getImage();
    HistogramViewer* getHistogramWindow();
    bool             loadImage(QString);
    float const      imageRatio();

    bool hasHistogram();
    bool hasImage();
    void updateImage(); // redraws the image in the viewer

signals:
    void imageChanged(PNM*);
    void viewerClosed(ImageViewer*);
    void imageUpdated();
    void lockTools();
    void unlockTools();

public slots:
    void destroyedHistogram();
    void closedHistogramWindow();
    void undo();

    // Notifications from transformations
    void toolProgress(int);
    void toolMessage(QString);
    void toolFinished();
    void updateImage(PNM*); // puts a new image in the viewer

    void transformationStarted();
    void transformationFinished();

private:
    Ui::ImageViewer* ui;
    HistogramViewer* histogramView;
    float            _zoomRatio;
    QString          _filename;
    QString          _path;
    QList<PNM*>      history;
    bool             locked;

protected:
    void resizeEvent(QResizeEvent*);
    void closeEvent(QCloseEvent*);
    void updateTitle();
};

#endif // IMAGEVIEWER_H
