#include "linear_dialog.h"
#include "ui_linear_dialog.h"

LinearDialog::LinearDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::LinearDialog)
{
    setWindowModality(Qt::WindowModal);
    ui->setupUi(this);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    ui->comboMask->addItem("3x3", 3);
    ui->comboMask->addItem("5x5", 5);
    ui->comboMask->addItem("7x7", 7);

    }

LinearDialog::~LinearDialog()
{
    delete ui;
}

void LinearDialog::on_okButton_clicked()
{
    this->accept();
    this->close();
}

int LinearDialog::getSize()
{
    return ui->comboMask->itemData(ui->comboMask->currentIndex()).toInt();
}

void LinearDialog::on_comboMask_currentIndexChanged(int index)
{
    int size = ui->comboMask->itemData(index).toInt();
    ui->tableMask->setRowCount(size);
    ui->tableMask->setColumnCount(size);
 }

int LinearDialog::getShift()
{
    return ui->spinShift->value();
}

bool LinearDialog::getNormalize()
{
    return ui->checkNormalize->isChecked();
}

QList<QVariant> LinearDialog::getMask()
{
    int size = getSize();
    QList<QVariant> mask;

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            mask.append(ui->tableMask->model()->data(ui->tableMask->model()->index(i,j)).toDouble());

    return mask;
}
