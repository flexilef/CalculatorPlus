#include <QMessageBox>
#include <QLabel>

#include "include/gui/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cgui = new CalculatorGUI(this);
    setCentralWidget(cgui);

    connect(cgui, SIGNAL(statusBarEvent(QString)), this, SLOT(setStatusBarText(QString)));
    connect(cgui, SIGNAL(checkDegreesEvent()), this, SLOT(checkDegreesAction()));
    connect(cgui, SIGNAL(checkRadiansEvent()), this, SLOT(checkRadiansAction()));

    angleModeMessage = new QLabel(this);
    angleModeMessage->setText("Mode: degrees");
    ui->statusBar->addWidget(angleModeMessage);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete cgui;
    delete ui;
}

void MainWindow::setStatusBarText(const QString& message)
{
    angleModeMessage->setText(message);
}

void MainWindow::checkDegreesAction()
{
    degreesAct->setChecked(true);
}

void MainWindow::checkRadiansAction()
{
    radiansAct->setChecked(true);
}

void MainWindow::createActions()
{
    newAct = new QAction("&New", this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip("Create a new session");
    connect(newAct, SIGNAL(triggered()), this, SLOT(newAction()));

    copyAct = new QAction("&Copy", this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip("Copy highlighted text");
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copyAction()));

    pasteAct = new QAction("&Paste", this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip("Paste text");
    connect(pasteAct, SIGNAL(triggered()), this, SLOT(pasteAction()));

    selectAllAct = new QAction("&Select All", this);
    selectAllAct->setShortcuts(QKeySequence::SelectAll);
    selectAllAct->setStatusTip("Select all text");
    connect(selectAllAct, SIGNAL(triggered()), this, SLOT(selectAllAction()));

    clearAct = new QAction("Clea&r", this);
    clearAct->setShortcut(QKeySequence("Escape"));
    clearAct->setStatusTip("Clear text");
    connect(clearAct, SIGNAL(triggered()), this, SLOT(clearAction()));

    helpAct = new QAction("&Help", this);
    helpAct->setShortcuts(QKeySequence::HelpContents);
    helpAct->setStatusTip("View Help");
    connect(helpAct, SIGNAL(triggered()), this, SLOT(helpAction()));

    aboutAct = new QAction("&About ST Calculator", this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutAction()));

    radiansAct = new QAction("&Radians", this);
    radiansAct->setCheckable(true);
    connect(radiansAct, SIGNAL(triggered()), this, SLOT(radiansAction()));

    degreesAct = new QAction("&Degrees", this);
    degreesAct->setCheckable(true);
    degreesAct->setChecked(true);
    connect(degreesAct, SIGNAL(triggered()), this, SLOT(degreesAction()));

    angleActGroup = new QActionGroup(this);
    angleActGroup->addAction(radiansAct);
    angleActGroup->addAction(degreesAct);
    angleActGroup->setExclusive(true);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu("&New");
    fileMenu->addAction(newAct);

    editMenu = menuBar()->addMenu("&Edit");
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addAction(selectAllAct);
    editMenu->addAction(clearAct);
    //editMenu->addSeparator();

    settingsMenu = menuBar()->addMenu("&Settings");
    settingsMenu->addActions(angleActGroup->actions());

    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(helpAct);
    helpMenu->addAction(aboutAct);
    //helpMenu->addSeparator();
}

void MainWindow::newAction()
{
    cgui->clearTextBrowser();
}

void MainWindow::copyAction()
{
    if(cgui->focusOnLineEdit())
        cgui->copyLineEdit();
    else if(cgui->focusOnTextBroswer())
        cgui->copyTextBrowser();
}

void MainWindow::pasteAction()
{
    if(cgui->focusOnLineEdit())
        cgui->pasteLineEdit();
}

void MainWindow::selectAllAction()
{
    if(cgui->focusOnLineEdit())
        cgui->selectAllLineEdit();
    else if(cgui->focusOnTextBroswer())
        cgui->selectAllTextBrowser();
}

void MainWindow::clearAction()
{
    cgui->clearLineEdit();
}

void MainWindow::radiansAction()
{
    cgui->setRadiansMode();
    angleModeMessage->setText("Mode: radians");
}

void MainWindow::degreesAction()
{
    cgui->setDegreesMode();
    angleModeMessage->setText("Mode: degrees");
}

void MainWindow::helpAction()
{
    //replace this with actual code
    QMessageBox::information(this, "title", "help");
}

void MainWindow::aboutAction()
{
    aDialog = new AboutDialog(this);
    aDialog->show();
}
