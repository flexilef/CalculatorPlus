#include <QApplication>
#include <QPushButton>

#include "include/gui/mainwindow.h"
#include "include/gui/calculatorgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("ST Calculator");

    w.show();

    return a.exec();
}
