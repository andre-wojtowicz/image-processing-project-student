#ifndef HOUGH_DIALOG_H
#define HOUGH_DIALOG_H

#include <QDialog>

namespace Ui {
    class HoughDialog;
}

class HoughDialog : public QDialog
{
    Q_OBJECT
public:
    explicit HoughDialog(QWidget* parent = 0);
    ~HoughDialog();

    int    getThetaDensity();

private:
    Ui::HoughDialog* ui;
};

#endif // HOUGH_DIALOG_H
