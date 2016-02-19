#ifndef LINEAR_DIALOG_H
#define LINEAR_DIALOG_H

#include <QDialog>

namespace Ui
{
    class LinearDialog;
}

class LinearDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LinearDialog(QWidget* parent = 0);
    ~LinearDialog();

    int             getSize();
    QList<QVariant> getMask();
    bool            getNormalize();
    int             getShift();

private slots:
    void on_comboMask_currentIndexChanged(int index);
    void on_okButton_clicked();

private:
    Ui::LinearDialog* ui;
};

#endif // LINEAR_DIALOG_H
