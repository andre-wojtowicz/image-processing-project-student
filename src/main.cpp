#include "gui/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QPixmap(":icons/icons/picture.png"));

    MainWindow w;
    w.show();

    QObject::connect(&w, SIGNAL(exitApplication()), &a, SLOT(closeAllWindows()));

    return a.exec();
}
