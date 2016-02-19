#include "corner_harris_dialog.h"
#include "ui_corner_harris_dialog.h"

CornerHarrisDialog::CornerHarrisDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::CornerHarrisDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

CornerHarrisDialog::~CornerHarrisDialog()
{
    delete ui;
}

int CornerHarrisDialog::getThreshold()
{
    return ui->sB_threshold->value();
}

double CornerHarrisDialog::getSigma()
{
    return ui->dSB_sigma->value();
}

double CornerHarrisDialog::getSigmaWeight()
{
    return ui->dSB_sigma_weight->value();
}

double CornerHarrisDialog::getK()
{
    return ui->dSB_k->value();
}
