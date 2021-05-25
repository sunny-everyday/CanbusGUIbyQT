#include "mainwindow.h"
#include <QApplication>
#include <qdir.h>
#include "log.h"


int main(int argc, char *argv[])
{
    QT_LOG::logInit(QString(argv[0]).split(QDir::separator()).last().remove(".exe") + ".log");


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
