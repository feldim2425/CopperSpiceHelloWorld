//#include "mainwindow.h"
#include "mainwindow.hpp"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow dw;
    dw.show();
    return app.exec();
}