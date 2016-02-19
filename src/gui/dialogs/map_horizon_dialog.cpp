#include "map_horizon_dialog.h"
#include "ui_map_horizon_dialog.h"

MapHorizonDialog::MapHorizonDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MapHorizonDialog)
{
    ui->setupUi(this);
    setFixedSize(size());

    ui->cB_direction->addItem("North", MapHorizon::NORTH);
    ui->cB_direction->addItem("South", MapHorizon::SOUTH);
    ui->cB_direction->addItem("East",  MapHorizon::EAST);
    ui->cB_direction->addItem("West",  MapHorizon::WEST);
}

MapHorizonDialog::~MapHorizonDialog()
{
    delete ui;
}

int MapHorizonDialog::getAlpha()
{
    return ui->sB_alpha->value();
}

double MapHorizonDialog::getScale()
{
    return ui->dSB_scale->value();
}

MapHorizon::DIRECTION MapHorizonDialog::getDirection()
{
    return (MapHorizon::DIRECTION) ui->cB_direction->itemData(ui->cB_direction->currentIndex()).toInt();
}
