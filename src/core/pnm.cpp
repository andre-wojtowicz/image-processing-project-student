#include "pnm.h"

#include "histogram.h"

#include <QBuffer>
#include <QDebug>
#include <QFileDialog>


/** Creates a NULL QImage */
PNM::PNM() :
    QImage()
{
    histogram = 0;
}

/**
* Creates a new PNM image loaded from given path
* @eg:
    PNM image1 = PNM("/home/file.pbm");
    PNM image2 = PNM("/home/file2.ppm");
*/
PNM::PNM(QString path) :
    QImage(path)
{
    histogram = 0;
}

/**
  * Creates a new PNM image from a QImage
  */
PNM::PNM(QImage img) :
    QImage(img), histogram(0)
{
}

/**
  * Creates a new empty PNM with chosen QImage format
  */
PNM::PNM(int width, int height, QImage::Format format) :
    QImage(width, height, format), histogram(0)
{
    switch (format)
    {
    case QImage::Format_Mono:
        break;
    case QImage::Format_Grayscale8:
        this->setColorCount(256);

        for (int i = 0; i < 256; i++)
            this->setColor(i, qRgb(i, i, i));
        break;
    case QImage::Format_RGB32:
        break;
    default:
        qDebug() << "Not supported image type!";
    }

    this->fill(Qt::color0);
}

/**
  * Loads a file from given path
  * Created to comply with PTO standard
  */
void PNM::loadFile(QString filename)
{
    load(filename);
}

PNM::~PNM()
{
    if (histogram)
        delete histogram;
}

/**
  * Saves a Image file in PNM format. This methods displays a Save File dialog
  * if mode is set the file is written using given mode. Otherwise Binary is used. */
void PNM::saveFile(Mode mode = Binary)
{
    QString filename = QFileDialog::getSaveFileName(
                0,
                "Save File",
                "hag_image.pbm",
                "Filetype (*.pbm);;Grayscale (*.pgm);;Policolor (*.ppm)");

    QFileInfo fi(filename);
    if (mode == PNM::ASCII)
    {
        if (fi.suffix()== "pbm")      saveTextPBM(filename);
        else if (fi.suffix()== "pgm") saveTextPGM(filename);
        else if(fi.suffix()==  "ppm") saveTextPPM(filename);
        else qWarning() << "Wrong format selected!";
    }
    else
    {
        if (fi.suffix()== "pbm")     saveBinPBM(filename);
        else if(fi.suffix()== "pgm") saveBinPGM(filename);
        else if(fi.suffix()== "ppm") saveBinPPM(filename);
        else qWarning() << "Wrong format selected!";
    }
}

void PNM::saveTextPBM(QString filename)
{
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::WriteOnly);
    file.write("P1\n");
    file.write("# Created using PTO\n");
    file.write(QString("%1 %2\n").arg(width()).arg(height()).toLatin1());

    for(int y = 0; y<height(); y++)
    {
        for(int x = 0; x<width(); x++)
        {
            int p = 0;
            if (qGray(pixel(x,y))<=127) p = 1;
            file.write(QString(" %1").arg(p).toLatin1());
        }
        file.write("\n");
    }
    file.close();
}

void PNM::saveBinPBM(QString filename)
{
    QFile file;
    file.setFileName(filename);

    // first part ascii
    file.open(QIODevice::WriteOnly);
    file.write("P4\n");
    file.write("# Created using PTO\n");
    file.write(QString("%1 %2\n").arg(width()).arg(height()).toLatin1());

    //second part binary

    QDataStream out(&file);
    unsigned char byte = 0;
    unsigned char position = 0;

    for(int y = 0; y<height(); y++)
    {
        for(int x = 0; x<width(); x++)
        {
            if (qGray(pixel(x,y)) <= 127)
            {
                byte = byte | (1 << (7-position));
            }

            if (position == 7)
            {
                out << byte;
                byte = 0;
            }
            position = (position + 1) % 8;
        }

        if (position != 0)
        {
            out << byte;
        }

        byte = 0;
        position = 0;
    }
    file.close();
}

void PNM::saveBinPGM(QString filename)
{
    QFile file;
    file.setFileName(filename);

    // first part ascii
    file.open(QIODevice::WriteOnly);
    file.write("P5\n");
    file.write("# Created using PTO\n");
    file.write(QString("%1 %2\n255\n").arg(width()).arg(height()).toLatin1());

    //second part binary

    QDataStream out(&file);
    for(int y = 0; y<height(); y++)
    {
        for(int x = 0; x<width(); x++)
        {
            out << ((unsigned char) qGray(pixel(x,y)));
        }
    }
    file.close();
}

void PNM::saveBinPPM(QString filename)
{
    QFile file;
    file.setFileName(filename);

    // first part ascii
    file.open(QIODevice::WriteOnly);
    file.write("P6\n");
    file.write("# Created using PTO\n");
    file.write(QString("%1 %2\n255\n").arg(width()).arg(height()).toLatin1());

    //second part binary

    QDataStream out(&file);
    for(int y = 0; y<height(); y++)
    {
        for(int x = 0; x<width(); x++)
        {
            out << ((unsigned char) qRed(pixel(x,y)));
            out << ((unsigned char) qGreen(pixel(x,y)));
            out << ((unsigned char) qBlue(pixel(x,y)));
        }
    }
    file.close();
}


void PNM::saveTextPGM(QString filename) {
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::WriteOnly);
    file.write("P2\n");
    file.write("# Created using PTO\n");
    file.write(QString("%1 %2\n255\n").arg(width()).arg(height()).toLatin1());

    for(int y = 0; y<height(); y++)
    {
        for(int x = 0; x<width(); x++)
        {
            file.write(QString(" %1").arg(qGray(pixel(x,y))).toLatin1());
        }
        file.write("\n");
    }
    file.close();
}

void PNM::saveTextPPM(QString filename) {
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::WriteOnly);
    file.write("P3\n");
    file.write("# Created using PTO\n");
    file.write(QString("%1 %2\n255\n").arg(width()).arg(height()).toLatin1());

    for(int y = 0; y<height(); y++)
    {
        for(int x = 0; x<width(); x++)
        {
            QRgb p = pixel(x,y);
            file.write(QString("%1 %2 %3 ").arg(qRed(p)).arg(qGreen(p)).arg(qBlue(p)).toLatin1());
        }
        file.write("\n");
    }
    file.close();
}

/**
  * Returns a QByteArray containing a PNM image data in PPM format
  */
QByteArray* PNM::getData()
{
    QByteArray* ba = new QByteArray();
    QBuffer buffer(ba);
    buffer.open(QIODevice::WriteOnly);
    save(&buffer, "PPM");

    return ba;
}

/**
  * Returns a uchar array containing a PNM image data in CMYK format
  */
uchar* PNM::getCMYK()
{
    if(this->format() != QImage::Format_RGB32)
    {
        qWarning("Conversion to CMYK works only with color image!");
        return NULL;
    }

    uchar *bits = new uchar[this->width()*this->height()*4];

    for(int i=0; i<this->width(); i++)
    {
        for(int j=0; j<this->height(); j++)
        {
            QRgb pixel = this->pixel(i, j);
            int R = qRed(pixel),
                G = qGreen(pixel),
                B = qBlue(pixel);
            double C,M,Y,K, var_K;

            C = 1 - ( R / 255. );
            M = 1 - ( G / 255. );
            Y = 1 - ( B / 255. );
            var_K = 1;
            if ( C < var_K ) var_K = C;
            if ( M < var_K ) var_K = M;
            if ( Y < var_K ) var_K = Y;
            if ( var_K == 1 )
            {
                C = 0;
                M = 0;
                Y = 0;
            }
            else
            {
                C = ( C - var_K ) / ( 1 - var_K );
                M = ( M - var_K ) / ( 1 - var_K );
                Y = ( Y - var_K ) / ( 1 - var_K );
            }
            K = var_K;

            bits[i*this->width() + j*4]     = (int) C*100;
            bits[i*this->width() + j*4 + 1] = (int) M*100;
            bits[i*this->width() + j*4 + 2] = (int) Y*100;
            bits[i*this->width() + j*4 + 3] = (int) K*100;
        }
    }

    return bits;
}

Histogram* PNM::getHistogram()
{
    if (histogram)
    {
        return histogram;
    }
    else {
        histogram = new Histogram(this);
        return histogram;
    }
}

QPoint PNM::center()
{
    return QPoint(height()/2, width()/2);
}
