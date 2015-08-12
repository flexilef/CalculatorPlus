/*
This file is part of Calculator+
Copyright (C) 2015 Felix Lee

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <QPixmap>

#include "include/gui/aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("About Calculator+");
    setFixedSize(345, 300);

    QString message;
    QLabel* body;

    message += "<p align=Center>";
    message += "<br><img src=\":/images/graphics/blackboard96.png\"><br>";
    message += "<b>Calculator+ v1.0.0</b>"
               "<br>Calculator+ is a simple-to-use, button-free, scientific calculator.</br>"
               "<br>Copyright (C) 2015 Felix Lee</br></p>"

               "<p align=Center>This program is free software: you can redistribute it and/or modify</br>"
               "<br>it under the terms of the GNU General Public License as published by</br>"
               "<br>the Free Software Foundation, either version 3 of the License, or</br>"
               "<br>(at your option) any later version.</br></p>"

               "<p align=Center>This program is distributed in the hope that it will be useful,"
               "<br>but WITHOUT ANY WARRANTY; without even the implied warranty of</br>"
               "<br>MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the</br>"
               "<br>GNU General Public License for more details.</br></p>";

    body = new QLabel(this);
    body->setText(message);
}

AboutDialog::~AboutDialog()
{
}

