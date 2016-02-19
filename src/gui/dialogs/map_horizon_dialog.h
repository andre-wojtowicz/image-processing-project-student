#ifndef MAP_HORIZON_DIALOG_H
#define MAP_HORIZON_DIALOG_H

#include "core/transformations/map_horizon.h"

#include <QDialog>

namespace Ui {
    class MapHorizonDialog;
}

class MapHorizonDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MapHorizonDialog(QWidget* parent = 0);
    ~MapHorizonDialog();

    int                   getAlpha();
    double                getScale();
    MapHorizon::DIRECTION getDirection();

private:
    Ui::MapHorizonDialog* ui;
};

#endif // MAP_HORIZON_DIALOG_H
