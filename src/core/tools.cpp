#include "tools.h"

#include "transformations.h"
#include "gui/dialogs.h"
#include "gui/toolsmenu.h"

Tools::Tools(ImageViewer* iv, QObject* parent) :
    QObject(parent)
{
    setViewer(iv);
}

/*
 *
 * ------------------------ LAB. 1 -------------------------
 *
 */

void Tools::negativeImage()
{
    ImageViewer* iv = getViewer(); // Get the ImageViewer which holds the image.

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    NegativeImage* ni = new NegativeImage(iv->getImage(), iv);
    ni->start();
}

void Tools::convertToGrayScale()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_RGB32))
        return;

    ConversionGrayscale* cg = new ConversionGrayscale(iv->getImage(), iv);
    cg->start();
}

void Tools::correctBrightnessContrastGamma()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;


    CorrectionDialog dialog;
    dialog.setImage(iv->getImage()->copy());
    dialog.update();

    if (dialog.exec() == QDialog::Rejected)
        return;

    Correction* bc = new Correction(iv->getImage(), iv);
    bc->setParameter("shift",  dialog.getShift());
    bc->setParameter("factor", dialog.getMultiplier());
    bc->setParameter("gamma",  dialog.getGamma());

    bc->start();
}

/*
 *
 * ------------------------ LAB. 2 -------------------------
 *
 */

void Tools::histogramEqualize()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    HistogramEqualization* heq = new HistogramEqualization(iv->getImage(), iv);
    heq->start();
}

void Tools::histogramStretch()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    HistogramStretching* hs = new HistogramStretching(iv->getImage(), iv);
    hs->start();
}

void Tools::histogramShow()
{
    ImageViewer* iv = getViewer();

    if (iv)
        iv->getHistogramWindow();
}

/*
 *
 * ------------------------ LAB. 3 -------------------------
 *
 */

void Tools::blurGauss()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    GaussianDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    BlurGaussian* bg = new BlurGaussian(iv->getImage(), iv);
    bg->setParameter("size",  dialog.getSize());
    bg->setParameter("sigma", dialog.getSigma());

    bg->start();
}

void Tools::blurLinear()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    LinearDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    BlurLinear* bl = new BlurLinear(iv->getImage(), iv);
    bl->setParameter("size",      dialog.getSize());
    bl->setParameter("normalize", dialog.getNormalize());
    bl->setParameter("mask",      dialog.getMask());

    bl->start();
}

void Tools::blurUniform()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    BlurUniform* bu = new BlurUniform(iv->getImage(), iv);
    bu->start();
}

/*
 *
 * ------------------------ LAB. 4 -------------------------
 *
 */

void Tools::binGradient()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    BinarizationGradient* bg = new BinarizationGradient(iv->getImage(), iv);
    bg->start();
}

void Tools::binIterBimodal()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    BinarizationIterBimodal* bim = new BinarizationIterBimodal(iv->getImage(), iv);
    bim->start();
}

void Tools::binManual()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    SliderDialog dialog(new BinarizationManual(new PNM(iv->getImage()->copy())), "threshold");
    dialog.setRange(PIXEL_VAL_MIN, PIXEL_VAL_MAX);
    dialog.initSliderValue(PIXEL_VAL_MAX/2);
    dialog.setImage(iv->getImage()->copy());
    dialog.update();

    if (dialog.exec() == QDialog::Rejected)
        return;

    BinarizationManual* bm = new BinarizationManual(iv->getImage(), iv);
    bm->setParameter("threshold", dialog.value());
    bm->start();
}

void Tools::binNiblack()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    BinNiblackDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    BinarizationNiblack* bn = new BinarizationNiblack(iv->getImage(), iv);
    bn->setParameter("r", dialog.getR());
    bn->setParameter("a", dialog.getA());
    bn->start();
}

void Tools::binOtsu()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    BinarizationOtsu* bo = new BinarizationOtsu(iv->getImage(), iv);
    bo->start();
}

/*
 *
 * ------------------------ LAB. 5 -------------------------
 *
 */

void Tools::noiseMedian()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    NoiseMedianDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    NoiseMedian* nm = new NoiseMedian(iv->getImage(), iv);
    nm->setParameter("radius", dialog.getRadius());
    nm->start();
}

void Tools::noiseBilateral()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    NoiseBilateralDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    NoiseBilateral* nb = new NoiseBilateral(iv->getImage(), iv);
    nb->setParameter("sigma_d", dialog.getSigmaD());
    nb->setParameter("sigma_r", dialog.getSigmaR());
    nb->start();
}

/*
 *
 * ------------------------ LAB. 6 -------------------------
 *
 */

void Tools::morphDilate()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    MorphDialog dialog;
    dialog.setWindowTitle("Dilate");

    if (dialog.exec() == QDialog::Rejected)
        return;

    MorphDilate* md = new MorphDilate(iv->getImage(), iv);
    md->setParameter("size",  dialog.getSize());
    md->setParameter("shape", (int)dialog.getShape());

    md->start();
}

void Tools::morphErode()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    MorphDialog dialog;
    dialog.setWindowTitle("Erode");

    if (dialog.exec() == QDialog::Rejected)
        return;

    MorphErode* me = new MorphErode(iv->getImage(), iv);
    me->setParameter("size",  dialog.getSize());
    me->setParameter("shape", (int)dialog.getShape());

    me->start();
}

void Tools::morphOpen()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    MorphDialog dialog;
    dialog.setWindowTitle("Open");

    if (dialog.exec() == QDialog::Rejected)
        return;

    MorphOpenClose* mo = new MorphOpenClose(iv->getImage(), iv);
    mo->setParameter("size",  dialog.getSize());
    mo->setParameter("shape", (int)dialog.getShape());
    mo->setParameter("type", (int)MorphOpenClose::Open);
    mo->start();
}

void Tools::morphClose()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    MorphDialog dialog;
    dialog.setWindowTitle("Close");

    if (dialog.exec() == QDialog::Rejected)
        return;

    MorphOpenClose* mc = new MorphOpenClose(iv->getImage(), iv);
    mc->setParameter("size",  dialog.getSize());
    mc->setParameter("shape", (int)dialog.getShape());
    mc->setParameter("type", (int)MorphOpenClose::Close);
    mc->start();
}

/*
 *
 * ------------------------ LAB. 7 -------------------------
 *
 */

void Tools::edgeSobel()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    EdgeSobel* es = new EdgeSobel(iv->getImage(), iv);
    es->start();
}

void Tools::edgePrewitt()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    EdgePrewitt* ep = new EdgePrewitt(iv->getImage(), iv);
    ep->start();
}

void Tools::edgeRoberts()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    EdgeRoberts* er = new EdgeRoberts(iv->getImage(), iv);
    er->start();
}

void Tools::edgeLaplacian()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    MaskDialog dialog;
    dialog.setWindowTitle("Laplacian");

    if (dialog.exec() == QDialog::Rejected)
        return;

    EdgeLaplacian* el = new EdgeLaplacian(iv->getImage(), iv);
    el->setParameter("size", dialog.getSize());

    el->start();
}

void Tools::edgeZero()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    EdgeZeroDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    EdgeZeroCrossing* ezc = new EdgeZeroCrossing(iv->getImage(), iv);
    ezc->setParameter("size",      dialog.getSize());
    ezc->setParameter("sigma",     dialog.getSigma());
    ezc->setParameter("threshold", dialog.getThreshold());
    ezc->start();
}

/*
 *
 * ------------------------ LAB. 8 -------------------------
 *
 */

void Tools::mapHeight()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    MapHeight* mh = new MapHeight(iv->getImage(), iv);
    mh->start();
}

void Tools::mapHorizon()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    MapHorizonDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    MapHorizon* mh = new MapHorizon(iv->getImage(), iv);
    mh->setParameter("scale", dialog.getScale());
    mh->setParameter("alpha", dialog.getAlpha());
    mh->setParameter("direction", (int)dialog.getDirection());
    mh->start();
}

void Tools::mapNormal()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_RGB32))
        return;

    MapNormalDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    MapNormal* mn = new MapNormal(iv->getImage(), iv);
    mn->setParameter("strength", dialog.getStrength());
    mn->start();
}

/*
 *
 * ------------------------ LAB. 9 -------------------------
 *
 */

void Tools::edgeCanny()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    EdgeCannyDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    EdgeCanny* ec = new EdgeCanny(iv->getImage(), iv);
    ec->setParameter("lower_threshold", dialog.getLowerThreshold());
    ec->setParameter("upper_threshold", dialog.getUpperThreshold());
    ec->start();
}

/*
 *
 * ------------------------ LAB. 10 ------------------------
 *
 */

void Tools::houghTransform()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Mono
                                                          << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    HoughDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    Hough* hough = new Hough(iv->getImage(), iv);
    hough->setParameter("theta_density", dialog.getThetaDensity());
    hough->setParameter("skip_edge_detection", false);
    hough->start();
}

void Tools::houghLines()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_RGB32))
        return;

    HoughLinesDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    HoughLines* hl = new HoughLines(iv->getImage(), iv);
    hl->setParameter("threshold",        dialog.getThreshold());
    hl->setParameter("draw_whole_lines", dialog.getDrawWholeLines());
    hl->start();
}

/*
 *
 * ------------------------ LAB. 11 ------------------------
 *
 */

void Tools::cornerHarris()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    CornerHarrisDialog dialog;
    if (dialog.exec() == QDialog::Rejected)
        return;

    CornerHarris* ch = new CornerHarris(iv->getImage(), iv);
    ch->setParameter("threshold",    dialog.getThreshold());
    ch->setParameter("sigma",        dialog.getSigma());
    ch->setParameter("sigma_weight", dialog.getSigmaWeight());
    ch->setParameter("k",            dialog.getK());
    ch->start();
}

/*
 *
 * ------------------------ LAB. 12 ------------------------
 *
 */

void Tools::houghRectangles()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_RGB32))
        return;

    HoughRectangles* hr = new HoughRectangles(iv->getImage(), iv);
    hr->start();
}

/*
 *
 * ------------------------ LAB. 13 ------------------------
 *
 */

void Tools::segmentation()
{
    ImageViewer* iv = getViewer();

    if (!SupportedImageFormat(iv, QList<QImage::Format>() << QImage::Format_Indexed8
                                                          << QImage::Format_RGB32))
        return;

    Segmentation* s = new Segmentation(iv->getImage(), iv);
    s->start();
}

/*
 *
 * ----------------------------------------------------------
 *
 */


void Tools::zoom(float factor)
{
    ImageViewer* iv = getViewer();
    if (!iv)
        return;
    iv->zoom(factor);
}

void Tools::rotate90()
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";
    // TODO
}

void Tools::rotate180()
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";
    // TODO
}

void Tools::rotate270()
{
    qDebug() << Q_FUNC_INFO << "Not implemented yet!";
    // TODO
}


ImageViewer* Tools::getViewer()
{
    return (m_iv->hasImage() ? m_iv : 0);
}

void Tools::setViewer(ImageViewer* iv)
{
    m_iv = iv;
}

bool Tools::SupportedImageFormat(ImageViewer* iv,
                                        QList<QImage::Format> formats)
{
    if (!iv)
        return false;

    for (int i = 0; i < formats.size(); ++i)
        if (iv->getImage()->format() == formats.at(i))
            return true;

    qWarning() << "Unsupported image type!";
    return false;
}
