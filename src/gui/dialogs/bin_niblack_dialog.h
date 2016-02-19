#ifndef BIN_NIBLACK_DIALOG_H
#define BIN_NIBLACK_DIALOG_H

#include <QDialog>

namespace Ui {
    class BinNiblackDialog;
}

class BinNiblackDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BinNiblackDialog(QWidget* parent = 0);
    ~BinNiblackDialog();

    int    getR();
    double getA();

private:
    Ui::BinNiblackDialog* ui;
};

#endif // BIN_NIBLACK_DIALOG_H
