#include "map_normal_dialog.h"
#include "ui_map_normal_dialog.h"

MapNormalDialog::MapNormalDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MapNormalDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

MapNormalDialog::~MapNormalDialog()
{
    delete ui;
}

double MapNormalDialog::getStrength()
{
    return ui->dSB_strength->value();
}
