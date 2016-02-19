#include "slider_dialog.h"
#include "ui_slider_dialog.h"

#include "core/transformations/transformation.h"

SliderDialog::SliderDialog(Transformation* transformation,
                           QString sliderParameter) :
    QDialog(0),
    ui(new Ui::SliderDialog)
{
    ui->setupUi(this);    
    m_transformation = transformation;
    m_parameter = sliderParameter;
    ui->previewLabel->setVisible(ui->previevBox->isChecked());
    ui->sliderLabel->setText(QString("0"));
}

SliderDialog::~SliderDialog()
{
    delete ui;
    delete m_transformation->getImage();
    delete m_transformation;
}

void SliderDialog::setupDialog()
{
    updatePreview();
}

void SliderDialog::initSliderValue(int val)
{
    setValue(val);
    ui->sliderLabel->setText(QString("%1").arg(val));
    ui->slider->setValue(val);
    m_transformation->setParameter(m_parameter, value());
}

void SliderDialog::updatePreview()
{

    if (ui->previevBox->isChecked())
    {
        m_transformation->setParameter(m_parameter, value());
        m_transformation->setParameter("silent", true);
        ui->previewLabel->resize(image().size());
        PNM* ptr_tImage = m_transformation->transform();
        ui->previewLabel->setPixmap(QPixmap::fromImage(ptr_tImage->copy()).scaledToWidth(PIXEL_VAL_MAX));
        delete ptr_tImage;
    }
    else
        ui->previewLabel->setPixmap(QPixmap::fromImage(image()).scaledToWidth(PIXEL_VAL_MAX));
}

void SliderDialog::on_previevBox_toggled(bool checked)
{
    ui->previewLabel->setVisible(checked);
    updatePreview();
}

void SliderDialog::on_slider_sliderMoved(int position)
{
    setValue(position);
    ui->sliderLabel->setText(QString("%1").arg(position));
    updatePreview();
}

QImage SliderDialog::image()
{
    return m_image;
}

void SliderDialog::setImage(QImage img)
{
    m_image = img.scaledToWidth(PIXEL_VAL_MAX);
    updatePreview();
}

void SliderDialog::setRange(int min, int max) {
    m_minimum = min;
    m_maximum = max;
    this->ui->slider->setRange(min, max);
}

int SliderDialog::minimum() const
{
    return m_minimum;
}

int SliderDialog::maximum() const
{
    return m_maximum;
}

int SliderDialog::value() const
{
    return m_value;
}

double SliderDialog::ratio()
{
    return (m_value-m_minimum)/(double)(m_maximum-m_minimum);
}

void SliderDialog::setValue(int arg)
{
    m_value = arg;
    m_transformation->setParameter(m_parameter, value());
}
