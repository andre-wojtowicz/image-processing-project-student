#ifndef CORRECTIONDIALOG_H
#define CORRECTIONDIALOG_H

#include <QDialog>

namespace Ui
{
    class CorrectionDialog;
}

class CorrectionDialog : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage)
public:
    explicit CorrectionDialog(QWidget* parent = 0);
    ~CorrectionDialog();

    void  setupDialog();
    float getShift();
    float getMultiplier();
    float getGamma();

    QImage image();
    void   setImage(QImage);

private slots:
    void on_correction_sliderMoved(int position);
    void on_previewBox_toggled(bool checked);
    void on_contrast_sliderMoved(int position);
    void on_okButton_clicked();
    void on_gamma_sliderMoved(int position);

private:
    void updatePreview();

    Ui::CorrectionDialog* ui;
    float shift;
    float multiplier;
    float gamma;
    QImage m_image;
};

#endif // CORRECTIONDIALOG_H
