#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include "calculatorgui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();
    void createMenus();

    Ui::MainWindow *ui;
    CalculatorGUI *cgui;

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
};

#endif // MAINWINDOW_H
