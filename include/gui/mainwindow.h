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
