#ifndef MASK_DIALOG_H
#define MASK_DIALOG_H

#include <QDialog>

namespace Ui {
    class MaskDialog;
}

class MaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MaskDialog(QWidget *parent = 0);
    ~MaskDialog();

    int getSize();

private slots:
    void on_okButton_clicked();

private:
    Ui::MaskDialog *ui;
};

#endif // MASK_DIALOG_H
