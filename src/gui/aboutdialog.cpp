#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>

#include "include/gui/aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
    const int LENGTH = 230;//180
    const int HEIGHT = 200;//200
    setWindowTitle("About Calculator+");
    setFixedSize(LENGTH, HEIGHT);

    QFont font1("Cambria", 14, QFont::Bold);
    QFont font2("Cambria", 11);

    image = new QLabel(this);
    image->setPixmap(QPixmap(":/images/graphics/Board-icon 64.png"));
    image->setAlignment(Qt::AlignCenter);

    title = new QLabel(this);
    title->setText("Calculator+");
    title->setFont(font1);
    title->setAlignment(Qt::AlignCenter);

    version = new QLabel(this);
    version->setText("v1.0.0.0");
    version->setFont(font2);
    version->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *layout1 = new QHBoxLayout();
    QVBoxLayout *layout2 = new QVBoxLayout();

    layout2->addWidget(title);
    layout2->addWidget(version);
    layout1->addWidget(image);
    layout1->addLayout(layout2);

    body = new QLabel(this);
    body->setText("Calculator+ \n"
                  "button-free scientific calculator\n");
    body->setFont(font2);
    body->setAlignment(Qt::AlignCenter);

    copyright = new QLabel(this);
    copyright->setText("Copyright (C) 2015 Felix Lee");
    copyright->setFont(font2);
    copyright->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout3 = new QVBoxLayout();
    layout3->addWidget(version);
    layout3->addWidget(body);
    layout3->addWidget(copyright);

    layout->addLayout(layout1);
    layout->addLayout(layout3);

    setLayout(layout);
}

AboutDialog::~AboutDialog()
{
    delete title;
    delete image;
}

