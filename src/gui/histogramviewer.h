#ifndef HISTOGRAMVIEWER_H
#define HISTOGRAMVIEWER_H

#include <QWidget>

class PNM;
class Histogram;

namespace Ui {
class HistogramViewer;
}

class HistogramViewer : public QWidget
{
    Q_OBJECT
public:
    explicit HistogramViewer(QWidget* = 0, Qt::WindowType = Qt::Widget);
    ~HistogramViewer();

public slots:
    void updateHistogram(PNM*);
    void updateHistogram(Histogram*);
    void drawHistogram();

signals:
    void closing();
    void imageChanged();

private slots:
    void on_toggleRed_clicked();
    void on_toggleGreen_clicked();
    void on_toggleBlue_clicked();
    void on_toggleGray_clicked();

private:
    void closeEvent(QCloseEvent*);
    void resizeEvent(QResizeEvent*);

    Ui::HistogramViewer *ui;
    
    // Histogram images:
    QImage histogram; // Composite image;
    QImage red;
    QImage green;
    QImage blue;
    QImage gray;
};

#endif // HISTOGRAMVIEWER_H
