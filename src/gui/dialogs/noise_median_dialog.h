#ifndef NOISE_MEDIAN_DIALOG_H
#define NOISE_MEDIAN_DIALOG_H

#include <QDialog>

namespace Ui {
    class NoiseMedianDialog;
}

class NoiseMedianDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NoiseMedianDialog(QWidget* parent = 0);
    ~NoiseMedianDialog();

    int    getRadius();

private:
    Ui::NoiseMedianDialog* ui;
};

#endif // NOISE_MEDIAN_DIALOG_H
