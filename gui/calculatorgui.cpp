#include "calculatorgui.h"

CalculatorGUI::CalculatorGUI(QWidget *parent) : QWidget(parent)
{
    lineEdit = new QLineEdit(this);
    textBrowser = new QTextBrowser(this);

    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(handleLineEdit()));

    //setup layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textBrowser);
    layout->addWidget(lineEdit);
    setLayout(layout);
}

CalculatorGUI::~CalculatorGUI()
{
    delete lineEdit;
    delete textBrowser;
}

void CalculatorGUI::handleLineEdit()
{
    QString str = lineEdit->text();
    textBrowser->append(str + "\n");
    lineEdit->clear();
}
