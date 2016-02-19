#ifndef SLIDERDIALOG_H
#define SLIDERDIALOG_H

#include <QDialog>

class Transformation;

namespace Ui
{
class SliderDialog;
}

class SliderDialog : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage)
    Q_PROPERTY(int value READ value WRITE setValue)    
public:
    explicit SliderDialog(Transformation*, QString);
    ~SliderDialog();

    QImage image();
    void setImage(QImage);
    int minimum() const;
    int maximum() const;
    int value() const;
    double ratio();

public slots:
    void setValue(int);
    void setRange(int, int);
    void setupDialog();
    void initSliderValue(int);
    void updatePreview();

private slots:
    void on_previevBox_toggled(bool);
    void on_slider_sliderMoved(int);

private:
    Ui::SliderDialog* ui;
    QImage            m_image;
    int               m_minimum;
    int               m_maximum;
    int               m_value;
    Transformation*   m_transformation;
    QString           m_parameter;
};

#endif // SLIDERDIALOG_H
