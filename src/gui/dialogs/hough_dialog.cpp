#include "hough_dialog.h"
#include "ui_hough_dialog.h"

HoughDialog::HoughDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::HoughDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

HoughDialog::~HoughDialog()
{
    delete ui;
}

int HoughDialog::getThetaDensity()
{
    return ui->sB_theta_density->value();
}
