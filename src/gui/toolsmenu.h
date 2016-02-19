#ifndef TOOLSMENU_H
#define TOOLSMENU_H

#include "imageviewer.h"

class Tools;

namespace Ui {
class ToolsMenu;
}

class ToolsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ToolsMenu(ImageViewer*, QWidget* parent = 0);
    ~ToolsMenu();

public slots:
    void contentChanged(QWidget*);
    void disableAllTools();
    void enableAllTools();

private slots:
    void on_histogramButton_clicked();
    void on_lightButton_clicked();
    void on_grayscaleButton_clicked();

    // Zoom buttons
    void on_zoominButton_clicked();
    void on_zoomoutButton_clicked();
    void on_zoomResetButton_clicked();

    void on_negativeButton_clicked();

private:
    Ui::ToolsMenu* ui;
    Tools*         m_tools;
    ImageViewer*   m_viewer;
};

#endif // TOOLSMENU_H
