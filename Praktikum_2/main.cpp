#include "mainwindow.h"
#include "qapplication.h"

#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    //für buttons auf deutsch
    QTranslator translator;
    if(translator.load("qtbade_de")) {
        a.installTranslator(&translator);
    }*/

    MainWindow w;
    w.show();

    return a.exec();
}
