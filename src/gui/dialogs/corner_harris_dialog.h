#ifndef CORNER_HARRIS_DIALOG_H
#define CORNER_HARRIS_DIALOG_H

#include <QDialog>

namespace Ui
{
    class CornerHarrisDialog;
}

class CornerHarrisDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CornerHarrisDialog(QWidget* parent = 0);
    ~CornerHarrisDialog();

    int    getThreshold();
    double getSigma();
    double getSigmaWeight();
    double getK();

private:
    Ui::CornerHarrisDialog* ui;
};

#endif // CORNER_HARRIS_DIALOG_H
