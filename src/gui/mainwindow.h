#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PROGRAM_NAME "PTO"
#define PROGRAM_VER "3.1.3.38"
#define DEFAULT_IMG "lenna_512x512.pnm"

#include <QMainWindow>
#include <QDockWidget>

class ImageViewer;
class PNM;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    void loadImage(QString);

signals:
    void exitApplication();
    void blockAllTools();

public slots:
    void updateTitle();

private slots:
    // Menu bar
    void on_actionExit_triggered();
    void on_actionOpen_triggered();
    void on_actionBinary_format_triggered();
    void on_actionText_format_triggered();

    void on_actionUndo_Ctrl_Z_triggered();

private:
    PNM*        currentImage();
    inline void setupToolbar();
    QString textFormat(QImage::Format format);

    Ui::MainWindow* ui;
    QDockWidget*    dockWidget;
    ImageViewer*    imageViewer;

protected:
    void resizeEvent(QResizeEvent*);
    void closeEvent(QCloseEvent*);
};

#endif // MAINWINDOW_H
