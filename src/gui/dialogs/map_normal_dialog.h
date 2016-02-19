#ifndef MAP_NORMAL_DIALOG_H
#define MAP_NORMAL_DIALOG_H

#include <QDialog>

namespace Ui {
    class MapNormalDialog;
}

class MapNormalDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MapNormalDialog(QWidget* parent = 0);
    ~MapNormalDialog();

    double getStrength();

private:
    Ui::MapNormalDialog* ui;
};

#endif // MAP_NORMAL_DIALOG_H
