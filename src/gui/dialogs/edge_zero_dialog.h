#ifndef EDGE_ZERO_DIALOG_H
#define EDGE_ZERO_DIALOG_H

#include <QDialog>

namespace Ui {
    class EdgeZeroDialog;
}

class EdgeZeroDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EdgeZeroDialog(QWidget* parent = 0);
    ~EdgeZeroDialog();

    int    getSize();
    double getSigma();
    int    getThreshold();

private:
    Ui::EdgeZeroDialog* ui;
};

#endif // EDGE_ZERO_DIALOG_H
