#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "toolsmenu.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QScrollArea>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imageViewer = new ImageViewer(this);
    connect(imageViewer, SIGNAL(imageUpdated()), this, SLOT(updateTitle()));

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::NoRole);
    scrollArea->setWidget(imageViewer);
    this->setCentralWidget(scrollArea);

    setupToolbar();
    setWindowTitle(QString("%1 %2").arg(PROGRAM_NAME).arg(PROGRAM_VER));

    if (QFile(DEFAULT_IMG).exists())
        loadImage(DEFAULT_IMG);
}

MainWindow::~MainWindow()
{
    delete dockWidget;
    delete imageViewer;
    delete ui;
}

/*****************************************************************/
/* MENU BAR ACTIONS                                              */
/*****************************************************************/
void MainWindow::on_actionExit_triggered()
{
    emit exitApplication();
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename  = QFileDialog::getOpenFileName(
                this,
                tr("Open Image"),
                ".",
                tr("Open image (*.pbm *.pgm *.ppm *)")
                );
    if(filename != "") loadImage(filename);
}

void MainWindow::on_actionBinary_format_triggered()
{
    if(currentImage())
        currentImage()->saveFile(PNM::Binary);
}

void MainWindow::on_actionText_format_triggered() {
    if(currentImage())
        currentImage()->saveFile(PNM::ASCII);
}

/*****************************************************************/
/* WINDOW EVENTS                                                 */
/*****************************************************************/
void MainWindow::resizeEvent(QResizeEvent*)
{
}

void MainWindow::closeEvent(QCloseEvent*)
{
}

/*****************************************************************/
/* IMAGE OPERATIONS                                              */
/*****************************************************************/
void MainWindow::loadImage(QString filename)
{
    if (imageViewer->loadImage(filename))
    {
        ui->actionBinary_format->setEnabled(true);
        ui->actionText_format->setEnabled(true);
        ui->actionClose->setEnabled(true);
    }
    else
    {
        qWarning() << "File type is not supported:" << filename;
        QMessageBox::critical(0, "Error!", QString("Can't open %1\nFile not supported!").arg(filename));
    }
}

/**
  * Returns a pointer to the current active image
  */
PNM* MainWindow::currentImage()
{
    if (imageViewer)
        return imageViewer->getImage();
    else
        return 0;
}


/** What to do when the Undo button is pressed! */
void MainWindow::on_actionUndo_Ctrl_Z_triggered()
{
    if (imageViewer->hasImage())
        imageViewer->undo();
}

/*****************************************************************/
/* WINDOWS OPERATIONS AND TOOLS                                  */
/*****************************************************************/
void MainWindow::updateTitle()
{
    // Title Format:
    // {filename.jpg} @ 100% - {program build}
    QString title = "%1 @ %2%3 (%4x%5 %6) - %7 %8";
    QString filename = imageViewer->fileName();
    float zoomFactor = imageViewer->getZoom();
    title = title.arg(filename).arg(zoomFactor*100).arg("%")
            .arg(imageViewer->getImage()->width())
            .arg(imageViewer->getImage()->height())
            .arg(textFormat(imageViewer->getImage()->format()))
            .arg(PROGRAM_NAME).arg(PROGRAM_VER);
    setWindowTitle(title);
}

QString MainWindow::textFormat(QImage::Format format)
{
    if (format == QImage::Format_RGB32)
        return "Color RGB 32-bit";
    else if (format == QImage::Format_Indexed8)
        return "Grayscale 8-bit";
    else if (format == QImage::Format_Mono)
        return "Black & white 1-bit";

    return "Unknown format.";
}

/** Small inline function which setups the toolbar. Adds the DockWidget to main window */
void MainWindow::setupToolbar()
{
        // Setting up the dockWidget:
        dockWidget = new QDockWidget(tr("Tools"), centralWidget());
        dockWidget->setFloating(true);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        dockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
        dockWidget->resize(150, 100);
        dockWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        //Setting up the ToolsMenu:
        ToolsMenu *tools = new ToolsMenu(imageViewer);
        tools->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        dockWidget->setWidget(tools);

        // Comunication with the tools menu:
        connect(this, SIGNAL(blockAllTools()), tools, SLOT(disableAllTools()));
}
