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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include <QLabel>

#include "calculatorgui.h"
#include "aboutdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    friend class calculatorgui;

private:

    void createActions();
    void createMenus();

    Ui::MainWindow *ui;
    CalculatorGUI *cgui;
    AboutDialog *aDialog;

    QLabel *angleModeMessage;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QMenu *settingsMenu;
    QAction *newAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *selectAllAct;
    QAction *clearAct;
    QAction *helpAct;
    QAction *aboutAct;
    QAction *radiansAct;
    QAction *degreesAct;
    QActionGroup *angleActGroup;

private slots:
    void newAction();
    void copyAction();
    void pasteAction();
    void selectAllAction();
    void clearAction();
    void helpAction();
    void aboutAction();
    void radiansAction();
    void degreesAction();

    //slots from calculatorgui
    void setStatusBarText(const QString&);
    void checkRadiansAction();
    void checkDegreesAction();
};

#endif // MAINWINDOW_H
