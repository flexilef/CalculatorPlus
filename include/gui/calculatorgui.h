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

#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QTextBrowser>
#include <QVBoxLayout>

#include "include/core/Calculator.h"

class CalculatorGUI : public QWidget
{
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = 0);
    ~CalculatorGUI();

    bool isCommand(const QString&);
    void runCommand(const QString&);

    void setRadiansMode();
    void setDegreesMode();
    void copyLineEdit();
    void copyTextBrowser();
    void pasteLineEdit();
    void clearLineEdit();
    void clearTextBrowser();
    void selectAllLineEdit();
    void selectAllTextBrowser();
    bool focusOnLineEdit();
    bool focusOnTextBroswer();

private:

    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;

    Calculator calc;
    std::vector<QString> history;
    int historyIndex;

protected:
    bool eventFilter(QObject *, QEvent *);
public slots:
    void handleLineEdit();

signals:
    void statusBarEvent(const QString&);
    void checkRadiansEvent();
    void checkDegreesEvent();
};

#endif // CALCULATORGUI_H
