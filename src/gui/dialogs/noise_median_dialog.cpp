#include "noise_median_dialog.h"
#include "ui_noise_median_dialog.h"

NoiseMedianDialog::NoiseMedianDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::NoiseMedianDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

NoiseMedianDialog::~NoiseMedianDialog()
{
    delete ui;
}

int NoiseMedianDialog::getRadius()
{
    return ui->sB_radius->value();
}
