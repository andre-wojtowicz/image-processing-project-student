#include "correction_dialog.h"
#include "ui_correction_dialog.h"

#include "core/transformations.h"

CorrectionDialog::CorrectionDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::CorrectionDialog)
{
    ui->setupUi(this);
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    shift      = 0.0;
    multiplier = 1.0;
    gamma      = 1.0;

    ui->correctionLabel->setText(QString("%1").arg(shift));
    ui->contrastLabel->setText(QString("%1").arg(multiplier));
    ui->gammaLabel->setText(QString("%1").arg(gamma));
}

CorrectionDialog::~CorrectionDialog()
{
    delete ui;
}

void CorrectionDialog::setupDialog()
{
    updatePreview();
}

QImage CorrectionDialog::image()
{
    return m_image;
}

void CorrectionDialog::setImage(QImage img)
{
    m_image = img.scaledToWidth(PIXEL_VAL_MAX);
    updatePreview();
}

void CorrectionDialog::updatePreview()
{
    PNM tImage(image());

    if (ui->previewBox->isChecked())
    {
        Correction bc(&tImage);
        bc.setParameter("shift", shift);
        bc.setParameter("factor", multiplier);
        bc.setParameter("gamma", gamma);
        bc.setParameter("silent", true);
        ui->preview->resize(image().size());
        PNM* ptr_tImage = bc.transform();
        ui->preview->setPixmap(QPixmap::fromImage(ptr_tImage->copy()));
        delete ptr_tImage;
    }
    else
        ui->preview->setPixmap(QPixmap::fromImage(image()));
}

float CorrectionDialog::getShift()
{
    return shift;
}

float CorrectionDialog::getMultiplier()
{
    return multiplier;
}

float CorrectionDialog::getGamma()
{
    return gamma;
}

void CorrectionDialog::on_previewBox_toggled(bool checked)
{
    updatePreview();
}

void CorrectionDialog::on_okButton_clicked()
{
    this->accept();
    this->close();
}

void CorrectionDialog::on_correction_sliderMoved(int position)
{
    shift = position-PIXEL_VAL_MAX;
    ui->correctionLabel->setText(QString("%1").arg(shift));

    updatePreview();
}

void CorrectionDialog::on_contrast_sliderMoved(int position)
{
    int v = position;
    multiplier = (v+500)/1000.0;
    ui->contrastLabel->setText(QString("%1").arg(multiplier));

    updatePreview();
}

void CorrectionDialog::on_gamma_sliderMoved(int position)
{
    int v = position;
    gamma = (v+500)/1000.0;
    ui->gammaLabel->setText(QString("%1").arg(gamma));

    updatePreview();
}
