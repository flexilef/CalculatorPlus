#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cgui = new CalculatorGUI(this);
    setCentralWidget(cgui);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete cgui;
    delete ui;
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

    aboutAct = new QAction("&About", this);
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
    //replace this with actual code
    QMessageBox::information(this, "title", "new");
}

void MainWindow::copyAction()
{
    //replace this with actual code
    QMessageBox::information(this, "title", "copy");
}

void MainWindow::pasteAction()
{
    //replace this with actual code
    QMessageBox::information(this, "title", "paste");
}

void MainWindow::selectAllAction()
{
    //replace this with actual code
    QMessageBox::information(this, "title", "select all");
}

void MainWindow::clearAction()
{
    //replace this with actual code
    QMessageBox::information(this, "title", "clear");
}

void MainWindow::radiansAction()
{
    cgui->setRadiansMode();
}

void MainWindow::degreesAction()
{
    cgui->setDegreesMode();
}

void MainWindow::helpAction()
{
    //replace this with actual code
    QMessageBox::information(this, "title", "help");
}

void MainWindow::aboutAction()
{
    //replace this with actual code
    QMessageBox::information(this, "title", "about");
}
