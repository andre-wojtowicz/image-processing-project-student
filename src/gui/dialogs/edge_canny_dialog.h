#ifndef EDGE_CANNY_DIALOG_H
#define EDGE_CANNY_DIALOG_H

#include <QDialog>

namespace Ui {
    class EdgeCannyDialog;
}

class EdgeCannyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EdgeCannyDialog(QWidget* parent = 0);
    ~EdgeCannyDialog();

    int getUpperThreshold();
    int getLowerThreshold();

private:
    Ui::EdgeCannyDialog* ui;
};

#endif // EDGE_CANNY_DIALOG_H
