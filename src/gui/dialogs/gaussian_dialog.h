#ifndef GAUSSIAN_DIALOG_H
#define GAUSSIAN_DIALOG_H

#include <QDialog>

namespace Ui {
    class GaussianDialog;
}

class GaussianDialog : public QDialog
{
    Q_OBJECT
public:
    explicit GaussianDialog(QWidget* parent = 0);
    ~GaussianDialog();

    int    getSize();
    double getSigma();

private slots:
    void on_okButton_clicked();

private:
    Ui::GaussianDialog* ui;
};

#endif // GAUSSIAN_DIALOG_H
