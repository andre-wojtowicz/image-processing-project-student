#define MAX_HISTORY     10
#define MAX_ZOOM_RATIO  16

#include "imageviewer.h"
#include "ui_imageviewer.h"

#include "histogramviewer.h"

#include <QResizeEvent>
#include <QFileInfo>

ImageViewer::ImageViewer(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);
    ui->dial->setVisible(false);
    histogramView = 0;
    resetZoom();
    locked = false;
}

QString ImageViewer::fileName()
{
    return _filename;
}

QString ImageViewer::path()
{
    return _path;
}

float ImageViewer::getZoom()
{
    return _zoomRatio;
}

void ImageViewer::setZoom(float factor)
{
    resetZoom();
    zoom(factor);
}

void ImageViewer::resetZoom()
{
    _zoomRatio = 1.0f;
}

/**
  * loads an image from given path and shows it in the viewer
  * Clears the history of the IV
  */
bool ImageViewer::loadImage(QString path)
{
    PNM* image = new PNM(path);

    if (image->isNull())
        return false;
    QFileInfo pathInfo(path);
    QString fileName(pathInfo.fileName());
    _filename = fileName;
    _path = path;

    history.clear();
    resetZoom();
    updateImage(image);
    updateTitle();

    return true;
}

ImageViewer::~ImageViewer()
{
    if (histogramView)
        closedHistogramWindow();

    if(ui)
        delete ui;
}


/**
  * Updates the view using the first element on the history list
  */
void ImageViewer::updateImage()
{
    PNM* image = history.first();
    ui->dial->setVisible(false);

    if (image)
    {
        ui->imageLabel->setGeometry(0, 0, image->width(), image->height());
        ui->imageLabel->setPixmap(QPixmap::fromImage(image->copy()));
        resize(image->size());
        emit imageChanged(image);
        emit imageUpdated();
        setZoom(getZoom()); // best solution ever
    }
    else
        qWarning("No image on the history list");
}


/**
  * Updates the view by pushing a new element to the history.
  * If image==0 then a nothing happens!
 */
void ImageViewer::updateImage(PNM* image)
{
    if (image)
    {
        history.prepend(image);

        if (history.length()>=MAX_HISTORY)
        {
            PNM* discardedImage = history.last();
            history.removeLast();
            delete discardedImage;
        }

        updateImage();
        emit imageChanged(image);
    }
}

/** Returns a width to height ratio of the loaded image
  * if there is no image 0.0 is returned */
float const ImageViewer::imageRatio()
{
    PNM* image = getImage();

    if (image)
        return image->width() / float(image->height());
    else
        return 1.0f;
}

/** resizeEvent (what happens when the widget is resized) */
void ImageViewer::resizeEvent(QResizeEvent* event)
{
    QSize newSize = event->size()/2;
    int w = ui->dial->width()/2;
    ui->dial->move(newSize.width()-w, newSize.height());

    return;

    /* UNUSED SINCE USING THE QScrollArea
     * Left for future generations!
     */
    /*
    if (!history.empty()) {
        QSize newSize = event->size();

        float imWidth   = (float)getImage()->width();
        //float imHeight  = (float)getImage()->height();
        float ivWidth   = (float)this->width();
        float ivHeight  = (float)this->height();
        float scaleH = ivWidth/imWidth;
        float scaleV = ivHeight/ivWidth;
        float maxScale = (scaleV>scaleH ? scaleV : scaleH);
        if (maxScale < 1.0) {
            setZoom(maxScale);
        }
        setZoom(1.0);
     }
        */

}


/** Returns a pointer to the PNM image held in the viewer */
PNM* ImageViewer::getImage()
{
    if (history.length()>0)
        return history.first();
    else
        return 0;
}

HistogramViewer* ImageViewer::getHistogramWindow()
{
    if (!hasImage())
        return 0;

    if (histogramView)
        return histogramView;
    else
    {
        histogramView = new HistogramViewer(0, Qt::Window);
        histogramView->showNormal();
        histogramView->setEnabled(true);
        histogramView->setWindowTitle("Histogram");
        histogramView->setWindowIcon(QPixmap(":icons/icons/chart_curve.png"));
        histogramView->updateHistogram(getImage());
        histogramView->drawHistogram();
        connect(this, SIGNAL(imageChanged(PNM*)), histogramView, SLOT(updateHistogram(PNM*)));
        connect(histogramView, SIGNAL(destroyed(QObject*)), this, SLOT(destroyedHistogram()));
        connect(histogramView, SIGNAL(closing()), this, SLOT(closedHistogramWindow()));
        return histogramView;
    }
}

bool ImageViewer::hasHistogram()
{
    if (histogramView)
        return true;
    else
        return false;
}

bool ImageViewer::hasImage()
{
    return !history.empty();
}

void ImageViewer::destroyedHistogram()
{
    disconnect(this, SLOT(destroyedHistogram()));
    disconnect(this, SLOT(closedHistogramWindow()));
    histogramView = 0;
}

void ImageViewer::closedHistogramWindow()
{
    disconnect(this, SLOT(destroyedHistogram()));
    disconnect(this, SLOT(closedHistogramWindow()));
    delete histogramView;
}

/** Updates the ImageViewer title showing its size, ratio and filename */
void ImageViewer::updateTitle()
{
    int ratio100 = (int)(_zoomRatio*100);

    // TODO: implement someday
    /*
    PNM* image = getImage();
    int width = 0, height = 0;
    if (image) {
        width = image->width();
        height = image->height();
    }
    */

    setWindowTitle(
        QString("%1 (%2% - %3x%4)")
        .arg(_filename)
        .arg(ratio100)
        .arg(getImage()->width())
        .arg(getImage()->height())
    );
    emit imageUpdated();
}


void ImageViewer::closeEvent(QCloseEvent*)
{
    emit viewerClosed(this);
    histogramView->close();
}


void ImageViewer::undo()
{
    if (locked)
        return;

    if (history.length()>1)
    {
        PNM* discardedImage = history.first();
        history.removeFirst();
        delete discardedImage;
    }

    updateImage();
}

/** Shows a progress bar with current transformation state
  * int progress - [0-100] current transformation progress in percents
  */
void ImageViewer::toolProgress(int progress)
{
    ui->dial->setVisible(true);
    ui->dial->setValue(progress);
    ui->dial->setTextVisible(true);
}

/** Changes the IV state when the transformations is finished
 *  Hides the progress bar etc.
 */
void ImageViewer::toolFinished()
{
    ui->dial->setValue(0);
    ui->dial->setFormat("%p%");
    ui->dial->setVisible(false);
    ui->dial->setTextVisible(false);
}

/** Shows a message in IV from current transformation */
void ImageViewer::toolMessage(QString message)
{
    ui->dial->setVisible(true);
    ui->dial->setTextVisible(true);
    ui->dial->setFormat(message);
}

/** Resizes the shown image using the zoom factor.
  * If factor is equal 0.0 zoom is reseted
  */
void ImageViewer::zoom(double factor)
{
    if (factor==0.0)
        _zoomRatio = 1.0;
    else if (factor > 1 && _zoomRatio >= MAX_ZOOM_RATIO)
        return;
    else
        _zoomRatio = getZoom()*factor;

    QImage resizedImage = getImage()->copy();
    int imWidth = resizedImage.width();
    int imHeight = resizedImage.height();
    resizedImage = resizedImage.scaled(imWidth*_zoomRatio, imHeight*_zoomRatio, Qt::KeepAspectRatio);
    ui->imageLabel->move(0,0);
    ui->imageLabel->resize(resizedImage.size());
    ui->imageLabel->setPixmap(QPixmap::fromImage(resizedImage));
    resize(resizedImage.size());
    updateTitle();
}

void ImageViewer::transformationStarted()
{
    locked = true;
    emit lockTools();
}

void ImageViewer::transformationFinished()
{
    locked = false;
    emit unlockTools();
}
