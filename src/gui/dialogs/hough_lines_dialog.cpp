#include "hough_lines_dialog.h"
#include "ui_hough_lines_dialog.h"

HoughLinesDialog::HoughLinesDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::HoughLinesDialog)
{
    ui->setupUi(this);
    setFixedSize(size());

    ui->cb_draw_whole_lines->addItem("false", false);
    ui->cb_draw_whole_lines->addItem("true",  true);
}

HoughLinesDialog::~HoughLinesDialog()
{
    delete ui;
}

int HoughLinesDialog::getThreshold()
{
    return ui->sB_theshold->value();
}

bool HoughLinesDialog::getDrawWholeLines()
{
    return ui->cb_draw_whole_lines->itemData(ui->cb_draw_whole_lines->currentIndex()).toBool();
}
