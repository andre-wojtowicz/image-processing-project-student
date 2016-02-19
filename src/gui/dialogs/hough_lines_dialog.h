#ifndef HOUGH_LINES_DIALOG_H
#define HOUGH_LINES_DIALOG_H

#include <QDialog>

namespace Ui {
    class HoughLinesDialog;
}

class HoughLinesDialog : public QDialog
{
    Q_OBJECT
public:
    explicit HoughLinesDialog(QWidget* parent = 0);
    ~HoughLinesDialog();

    int  getThreshold();
    bool getDrawWholeLines();

private:
    Ui::HoughLinesDialog* ui;
};

#endif // HOUGH_LINES_DIALOG_H
