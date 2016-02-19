#include "morph_dialog.h"
#include "ui_morph_dialog.h"

MorphDialog::MorphDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MorphDialog)
{
    ui->setupUi(this);

    ui->seSize->addItem("3x3", 3);
    ui->seSize->addItem("5x5", 5);
    ui->seSize->addItem("7x7", 7);

    ui->seShape->addItem("Square", MorphologicalOperator::Square);
    ui->seShape->addItem("Cross", MorphologicalOperator::Cross);
    ui->seShape->addItem("X Cross", MorphologicalOperator::XCross);
    ui->seShape->addItem("Vertical Line", MorphologicalOperator::VLine);
    ui->seShape->addItem("Horizontal Line", MorphologicalOperator::HLine);
}

MorphDialog::~MorphDialog()
{
    delete ui;
}

void MorphDialog::on_okButton_clicked()
{
    this->accept();
}

void MorphDialog::on_cancelButton_clicked()
{
    this->reject();
}

MorphologicalOperator::SE MorphDialog::getShape()
{
    return (MorphologicalOperator::SE) ui->seShape->itemData(ui->seShape->currentIndex()).toInt();
}

int MorphDialog::getSize()
{
    return ui->seSize->itemData(ui->seSize->currentIndex()).toInt();
}
