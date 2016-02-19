#include "edge_zero_dialog.h"
#include "ui_edge_zero_dialog.h"

EdgeZeroDialog::EdgeZeroDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::EdgeZeroDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
    ui->comboBox->addItem("3x3", 3);
    ui->comboBox->addItem("5x5", 5);
    ui->comboBox->addItem("7x7", 7);
    ui->comboBox->addItem("9x9", 9);
    ui->comboBox->addItem("11x11", 11);
    ui->comboBox->addItem("13x13", 13);
}

EdgeZeroDialog::~EdgeZeroDialog()
{
    delete ui;
}

int EdgeZeroDialog::getSize()
{
    return ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt();
}

double EdgeZeroDialog::getSigma()
{
    return ui->doubleSpinBox->value();
}

int EdgeZeroDialog::getThreshold()
{
    return ui->spinBox->value();
}
