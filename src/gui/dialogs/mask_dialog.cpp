#include "mask_dialog.h"
#include "ui_mask_dialog.h"

MaskDialog::MaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaskDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
    ui->comboBox->addItem("3x3", 3);
    ui->comboBox->addItem("5x5", 5);
    ui->comboBox->addItem("7x7", 7);
}

MaskDialog::~MaskDialog()
{
    delete ui;
}

void MaskDialog::on_okButton_clicked()
{
    this->accept();
    this->close();
}

int MaskDialog::getSize()
{
    return ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt();
}
