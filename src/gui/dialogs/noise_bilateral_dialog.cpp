#include "noise_bilateral_dialog.h"
#include "ui_noise_bilateral_dialog.h"

NoiseBilateralDialog::NoiseBilateralDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::NoiseBilateralDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

NoiseBilateralDialog::~NoiseBilateralDialog()
{
    delete ui;
}

int NoiseBilateralDialog::getSigmaD()
{
    return ui->sB_sigma_d->value();
}

int NoiseBilateralDialog::getSigmaR()
{
    return ui->sB_sigma_r->value();
}
