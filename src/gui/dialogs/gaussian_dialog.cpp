#include "gaussian_dialog.h"
#include "ui_gaussian_dialog.h"

GaussianDialog::GaussianDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::GaussianDialog)
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

GaussianDialog::~GaussianDialog()
{
    delete ui;
}

void GaussianDialog::on_okButton_clicked()
{
    this->accept();
    this->close();
}

int GaussianDialog::getSize()
{
    return ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt();
}

double GaussianDialog::getSigma()
{
    return ui->doubleSpinBox->value();
}
