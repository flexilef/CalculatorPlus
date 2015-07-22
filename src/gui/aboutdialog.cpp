#include <QPixmap>
#include <QVBoxLayout>
#include <QFont>

#include "include/gui/aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("About Calculator+");

    const int LENGTH = 180;
    const int HEIGHT = 200;

    resize(LENGTH, HEIGHT);
    setFixedSize(LENGTH, HEIGHT);

    image = new QLabel(this);
    image->setPixmap(QPixmap(":/images/graphics/Board-icon 64.png"));

    QFont font1("Verdana", 12, QFont::Bold);
    QFont font2("Verdana", 12);

    title = new QLabel(this);
    title->setText("Calculator+");
    title->setFont(font1);

    version = new QLabel(this);
    version->setText("v1.0.0.0");

    body = new QLabel(this);
    body->setText("Calculator+ - \n"
                  "A button-free scientific calculator. \n");

    copyright = new QLabel(this);
    copyright->setText("Copyright (C) 2015 Felix Lee");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(version);
    layout->addWidget(image);
    layout->addWidget(body);
    layout->addWidget(copyright);
    setLayout(layout);
}

AboutDialog::~AboutDialog()
{
    delete title;
    delete image;
}

