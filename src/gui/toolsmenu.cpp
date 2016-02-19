#include "toolsmenu.h"
#include "ui_toolsmenu.h"

#include "core/tools.h"

#include <QMenu>

ToolsMenu::ToolsMenu(ImageViewer* iv, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ToolsMenu)
{
    ui->setupUi(this);
    setLayout(ui->verticalLayoutWidget->layout());

    m_viewer = (ImageViewer*) iv;
    m_tools = new Tools(m_viewer, this);

    // locking tools menu when performing transformation

    connect(m_viewer, SIGNAL(lockTools()), this, SLOT(disableAllTools()));
    connect(m_viewer, SIGNAL(unlockTools()), this, SLOT(enableAllTools()));

    /* -------------------------------------------------------
     * ROTATION
     * ------------------------------------------------------- */

    connect(ui->rotate90Button, SIGNAL(clicked()), m_tools, SLOT(rotate90()));
    connect(ui->rotate180Button, SIGNAL(clicked()), m_tools, SLOT(rotate180()));
    connect(ui->rotate270Button, SIGNAL(clicked()), m_tools, SLOT(rotate270()));

    /* -------------------------------------------------------
     * HISTOGRAM
     * ------------------------------------------------------- */

    QMenu* hMenu = new QMenu(ui->histogramButton);
    hMenu->addAction(
                QIcon(":/icons/icons/chart_curve_error.png"),
                QString("Equalize histograms"),
                m_tools,
                SLOT(histogramEqualize())
                );
    hMenu->addAction(
                QIcon(":/icons/icons/chart_curve_go.png"),
                QString("Stretch histograms"),
                m_tools,
                SLOT(histogramStretch())
                );

    ui->histogramButton->setMenu(hMenu);

    /* -------------------------------------------------------
     * FILTERS (convolution, blur)
     * ------------------------------------------------------- */

    QMenu* bMenu = new QMenu(ui->blurButton);
    bMenu->addAction(
                QIcon(":/icons/icons/draw_convolve.png"),
                QString("Gaussian blur"),
                m_tools,
                SLOT(blurGauss())
                );
    bMenu->addAction(
                QIcon(":/icons/icons/draw_convolve.png"),
                QString("Uniform blur"),
                m_tools,
                SLOT(blurUniform())
                );
    bMenu->addAction(
                QIcon(":/icons/icons/flag_airfield_vehicle_safety.png"),
                QString("Custom linear filter"),
                m_tools,
                SLOT(blurLinear())
                );

    ui->blurButton->setMenu(bMenu);

    /* -------------------------------------------------------
     * BINARIZATION
     * ------------------------------------------------------- */

    QMenu* binMenu = new QMenu(ui->binarizationButton);
    binMenu->addAction(
                QIcon(":/icons/icons/universal_binary.png"),
                QString("Manual"),
                m_tools,
                SLOT(binManual())
                );
    binMenu->addAction(
                QIcon(":/icons/icons/universal_binary.png"),
                QString("Gradient"),
                m_tools,
                SLOT(binGradient())
                );
    binMenu->addAction(
                QIcon(":/icons/icons/universal_binary.png"),
                QString("Iterative bimodal"),
                m_tools,
                SLOT(binIterBimodal())
                );
    binMenu->addAction(
                QIcon(":/icons/icons/universal_binary.png"),
                QString("Niblack"),
                m_tools,
                SLOT(binNiblack())
                );
    binMenu->addAction(
                QIcon(":/icons/icons/universal_binary.png"),
                QString("Otsu"),
                m_tools,
                SLOT(binOtsu())
                );

    ui->binarizationButton->setMenu(binMenu);

    /* -------------------------------------------------------
     * NOISE REDUCTION
     * ------------------------------------------------------- */

    QMenu* nMenu = new QMenu(ui->noiseButton);
    nMenu->addAction(
                QIcon(":/icons/icons/checkerboard.png"),
                QString("Median"),
                m_tools,
                SLOT(noiseMedian())
                );
    nMenu->addAction(
                QIcon(":/icons/icons/checkerboard.png"),
                QString("Bilateral"),
                m_tools,
                SLOT(noiseBilateral())
                );

    ui->noiseButton->setMenu(nMenu);

    /* -------------------------------------------------------
     * MORPHOLOGICAL
     * ------------------------------------------------------- */

    QMenu* morphMenu = new QMenu(ui->morphButton);
    morphMenu->addAction(
                QIcon(":/icons/icons/arrow_out.png"),
                QString("Dilate"),
                m_tools,
                SLOT(morphDilate())
                );
    morphMenu->addAction(
                QIcon(":/icons/icons/arrow_in.png"),
                QString("Erode"),
                m_tools,
                SLOT(morphErode())
                );
    morphMenu->addAction(
                QIcon(":/icons/icons/arrow_divide.png"),
                QString("Open"),
                m_tools,
                SLOT(morphOpen())
                );
    morphMenu->addAction(
                QIcon(":/icons/icons/arrow_join.png"),
                QString("Close"),
                m_tools,
                SLOT(morphClose())
                );

    ui->morphButton->setMenu(morphMenu);

    /* -------------------------------------------------------
     * EDGE DETECTION
     * ------------------------------------------------------- */

    QMenu* eMenu = new QMenu(ui->edgeButton);
    eMenu->addAction(
                QIcon(":/icons/icons/key_s.png"),
                QString("Sobel"),
                m_tools,
                SLOT(edgeSobel())
                );
    eMenu->addAction(
                QIcon(":/icons/icons/key_p.png"),
                QString("Prewitt"),
                m_tools,
                SLOT(edgePrewitt())
                );
    eMenu->addAction(
                QIcon(":/icons/icons/key_r.png"),
                QString("Roberts"),
                m_tools,
                SLOT(edgeRoberts())
                );
    eMenu->addAction(
                QIcon(":/icons/icons/edge_detection.png"),
                QString("Laplacian"),
                m_tools,
                SLOT(edgeLaplacian())
                );
    eMenu->addAction(
                QIcon(":/icons/icons/edge_detection.png"),
                QString("Zero-crossing (LoG)"),
                m_tools,
                SLOT(edgeZero())
                );

    eMenu->addAction(
                QIcon(":/icons/icons/edge_detection.png"),
                QString("Canny"),
                m_tools,
                SLOT(edgeCanny())
                );

    ui->edgeButton->setMenu(eMenu);

    /* -------------------------------------------------------
     * TEXTURES
     * ------------------------------------------------------- */

    QMenu* texMenu = new QMenu(ui->textureButton);
    texMenu->addAction(
                QIcon(":/icons/icons/flag_airfield_vehicle_safety.png"),
                QString("Height map"),
                m_tools,
                SLOT(mapHeight())
                );
    texMenu->addAction(
                QIcon(":/icons/icons/flag_airfield_vehicle_safety.png"),
                QString("Normal map"),
                m_tools,
                SLOT(mapNormal())
                );
    texMenu->addAction(
                QIcon(":/icons/icons/flag_airfield_vehicle_safety.png"),
                QString("Horizon map"),
                m_tools,
                SLOT(mapHorizon())
                );
    ui->textureButton->setMenu(texMenu);

    /* -------------------------------------------------------
     * TRANSFORMATIONS
     * ------------------------------------------------------- */

    QMenu* transMenu = new QMenu(ui->transformationsButton);
    transMenu->addAction(
                QIcon(":/icons/icons/videodisplay.png"),
                QString("Hough"),
                m_tools,
                SLOT(houghTransform())
                );
    transMenu->addAction(
                QIcon(":/icons/icons/videodisplay.png"),
                QString("Hough - lines"),
                m_tools,
                SLOT(houghLines())
                );
    transMenu->addAction(
                QIcon(":/icons/icons/videodisplay.png"),
                QString("Hough - rectangles"),
                m_tools,
                SLOT(houghRectangles())
                );
    transMenu->addAction(
                QIcon(":/icons/icons/videodisplay.png"),
                QString("Segmentation"),
                m_tools,
                SLOT(segmentation())
                );
    ui->transformationsButton->setMenu(transMenu);

    /* -------------------------------------------------------
     * CORNER DETECTION
     * ------------------------------------------------------- */

    QMenu* cornerMenu = new QMenu(ui->cornerButton);
    cornerMenu->addAction(
                QIcon(":/icons/icons/things_digital.png"),
                QString("Harris"),
                m_tools,
                SLOT(cornerHarris())
                );
    ui->cornerButton->setMenu(cornerMenu);

}

ToolsMenu::~ToolsMenu()
{
    delete ui;
}

void ToolsMenu::on_histogramButton_clicked()
{
    m_tools->histogramShow();
}


void ToolsMenu::contentChanged(QWidget* content)
{
    if (content)
    {
        if(content->inherits("ImageViewer"))
            enableAllTools();

        if (content->inherits("HistogramViewer"))
        {
            disableAllTools();
            ui->histogramButton->setEnabled(true);
        }
    }
    else
        disableAllTools();
}

void ToolsMenu::disableAllTools()
{
    ui->zoominButton->setEnabled(false);
    ui->zoomoutButton->setEnabled(false);
    ui->zoomResetButton->setEnabled(false);
    ui->rotate90Button->setEnabled(false);
    ui->rotate180Button->setEnabled(false);
    ui->rotate270Button->setEnabled(false);
    ui->negativeButton->setEnabled(false);
    ui->grayscaleButton->setEnabled(false);
    ui->lightButton->setEnabled(false);
    ui->histogramButton->setEnabled(false);
    ui->blurButton->setEnabled(false);
    ui->binarizationButton->setEnabled(false);
    ui->noiseButton->setEnabled(false);
    ui->morphButton->setEnabled(false);
    ui->edgeButton->setEnabled(false);
    ui->textureButton->setEnabled(false);
    ui->transformationsButton->setEnabled(false);
    ui->cornerButton->setEnabled(false);

}

void ToolsMenu::enableAllTools()
{
    ui->zoominButton->setEnabled(true);
    ui->zoomoutButton->setEnabled(true);
    ui->zoomResetButton->setEnabled(true);
    ui->rotate90Button->setEnabled(true);
    ui->rotate180Button->setEnabled(true);
    ui->rotate270Button->setEnabled(true);
    ui->negativeButton->setEnabled(true);
    ui->grayscaleButton->setEnabled(true);
    ui->lightButton->setEnabled(true);
    ui->histogramButton->setEnabled(true);
    ui->blurButton->setEnabled(true);
    ui->binarizationButton->setEnabled(true);
    ui->noiseButton->setEnabled(true);
    ui->morphButton->setEnabled(true);
    ui->edgeButton->setEnabled(true);
    ui->textureButton->setEnabled(true);
    ui->transformationsButton->setEnabled(true);
    ui->cornerButton->setEnabled(true);
}

void ToolsMenu::on_zoominButton_clicked()
{
    m_tools->zoom(2.0);
}

void ToolsMenu::on_zoomoutButton_clicked()
{
    m_tools->zoom(0.5);
}

void ToolsMenu::on_lightButton_clicked()
{
    m_tools->correctBrightnessContrastGamma();
}

void ToolsMenu::on_grayscaleButton_clicked()
{
    m_tools->convertToGrayScale();
}

void ToolsMenu::on_zoomResetButton_clicked()
{
    m_tools->zoom(0.0);
}

void ToolsMenu::on_negativeButton_clicked()
{
   m_tools->negativeImage();
}
