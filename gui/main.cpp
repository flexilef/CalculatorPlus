#include "mainwindow.h"
#include <QApplication>
#include "calculatorgui.h"
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("SYCALC");

    w.show();

    return a.exec();
}
