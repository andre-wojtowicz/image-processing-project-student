#ifndef NOISE_BILATERAL_DIALOG_H
#define NOISE_BILATERAL_DIALOG_H

#include <QDialog>

namespace Ui {
    class NoiseBilateralDialog;
}

class NoiseBilateralDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NoiseBilateralDialog(QWidget* parent = 0);
    ~NoiseBilateralDialog();

    int getSigmaD();
    int getSigmaR();

private:
    Ui::NoiseBilateralDialog* ui;
};

#endif // NOISE_BILATERAL_DIALOG_H
