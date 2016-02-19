#ifndef MORPH_DIALOG_H
#define MORPH_DIALOG_H

#include "core/transformations/morphological_operator.h"

#include <QDialog>

namespace Ui
{
    class MorphDialog;
}

class MorphDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MorphDialog(QWidget* parent = 0);
    ~MorphDialog();

    MorphologicalOperator::SE getShape();
    int getSize();

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::MorphDialog* ui;
};

#endif // MORPH_DIALOG_H
