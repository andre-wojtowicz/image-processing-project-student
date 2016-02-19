#include "edge_canny_dialog.h"
#include "ui_edge_canny_dialog.h"

EdgeCannyDialog::EdgeCannyDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::EdgeCannyDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

EdgeCannyDialog::~EdgeCannyDialog()
{
    delete ui;
}

int EdgeCannyDialog::getLowerThreshold()
{
    return ui->sB_lower->value();
}

int EdgeCannyDialog::getUpperThreshold()
{
    return ui->sB_upper->value();
}
