#include "bin_niblack_dialog.h"
#include "ui_bin_niblack_dialog.h"

BinNiblackDialog::BinNiblackDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::BinNiblackDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

BinNiblackDialog::~BinNiblackDialog()
{
    delete ui;
}

int BinNiblackDialog::getR()
{
    return ui->sB_r->value();
}

double BinNiblackDialog::getA()
{
    return ui->dSB_a->value();
}
