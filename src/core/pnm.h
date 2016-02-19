#ifndef PNM_H
#define PNM_H

class Histogram;

#include <QImage>

/* experimental support for Image Watch extension in Visual Studio 2013;
 * may be commented when compiling under QT Creator;
 */
//#if _MSC_VER == 1800 && _DEBUG
//#include <QtGui/private/qimage_p.h>
//#endif

/**
  * This is a PNM format extension for the QImage class of Qt
  * It gives the options of reading and saving PNM format specified images
  * from files. PNM implements both the ASCII and Binary formats of PNM
  * @see: http://en.wikipedia.org/wiki/Portable_anymap
  */
class PNM : public QImage
{
public:
    enum Mode {Binary, ASCII};

    PNM();
    PNM(QString);
    PNM(QImage);
    PNM(int, int, QImage::Format);
    ~PNM();

    void        loadFile(QString); // loads a file from given path
    void        saveFile(Mode);    // saves a file to using a PNM::Mode (ASCII or Binary)
    QPoint      center();
    QByteArray* getData();
    uchar*      getCMYK();
    Histogram*  getHistogram();

private:
    // functions for saving the PNM file;
    // ASCII format:
    void saveTextPPM(QString);
    void saveTextPGM(QString);
    void saveTextPBM(QString);
    // Binary format:
    void saveBinPPM(QString);
    void saveBinPGM(QString);
    void saveBinPBM(QString);

    Histogram* histogram;
};

#endif // PNM_H
