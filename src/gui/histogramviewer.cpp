#include "histogramviewer.h"
#include "ui_histogramviewer.h"

#include "core/pnm.h"
#include "core/histogram.h"

#include <QPainter>

HistogramViewer::HistogramViewer(QWidget* parent, Qt::WindowType flags) :
    QWidget(parent),
    ui(new Ui::HistogramViewer)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

HistogramViewer::~HistogramViewer()
{
    delete ui;
}

/* updates the histograms in the image */
void HistogramViewer::updateHistogram(Histogram* hist)
{
    red   = hist->getImage(Histogram::RChannel, QColor(255,   0,   0, 255));
    green = hist->getImage(Histogram::GChannel, QColor(  0, 255,   0, 255));
    blue  = hist->getImage(Histogram::BChannel, QColor(  0,   0, 255, 255));
    gray  = hist->getImage(Histogram::LChannel, QColor( 30,  30,  30, 255));
    drawHistogram();
}

void HistogramViewer::updateHistogram(PNM* image)
{
    updateHistogram(image->getHistogram());
}

void HistogramViewer::drawHistogram()
{
    int width = ui->histogramLabel->width();
    int height = ui->histogramLabel->height();
    histogram =  QImage(width, height, QImage::Format_ARGB32);
    histogram.fill(0);

    QPainter painter(&histogram);
   // painter.d
    QRect target(0,0,width,height);
    //Draw background:
    painter.setBrush(Qt::transparent);
    painter.drawRect(0,0,width, height);
    painter.setCompositionMode(QPainter::CompositionMode_HardLight);

    if (ui->toggleGray->isChecked())
        painter.drawImage(target, gray);
    if (ui->toggleRed->isChecked())
        painter.drawImage(target, red);
    if (ui->toggleGreen->isChecked())
        painter.drawImage(target, green);
    if (ui->toggleBlue->isChecked())
        painter.drawImage(target, blue);

    painter.end();
    histogram.scaled(width, height);
    // Put the image on the canvas:
    ui->histogramLabel->setPixmap(QPixmap::fromImage(histogram));
}

void HistogramViewer::on_toggleRed_clicked()
{
    drawHistogram();
}

void HistogramViewer::on_toggleGreen_clicked()
{
    drawHistogram();
}

void HistogramViewer::on_toggleBlue_clicked()
{
    drawHistogram();
}

void HistogramViewer::on_toggleGray_clicked()
{
    drawHistogram();
}

void HistogramViewer::closeEvent(QCloseEvent*)
{
    emit(closing());
}

void HistogramViewer::resizeEvent(QResizeEvent*)
{
    drawHistogram();
}
