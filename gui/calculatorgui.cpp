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

    lineEdit->installEventFilter(this);
}

CalculatorGUI::~CalculatorGUI()
{
    delete lineEdit;
    delete textBrowser;
}

void CalculatorGUI::handleLineEdit()
{
    QString input = lineEdit->text();
    QString output;
    double result = 0;

    calc.setInput(input.toStdString());
    calc.calculate();

    if(calc.getCalculatorState() == Calculator::ERRORSTATE)
    {
        output = QString::fromStdString(calc.getErrorMessage());
        calc.setCalculatorState(Calculator::RUNNINGSTATE);
    }
    else
    {
        result = calc.getOutput();
        output = QString::number(result);
    }

    textBrowser->append(input + "\n = " + output + "\n");

    lineEdit->clear();
}

void CalculatorGUI::setRadiansMode()
{
    calc.setAngleMode(MathUtil::RADIANS);
}

void CalculatorGUI::setDegreesMode()
{
    calc.setAngleMode(MathUtil::DEGREES);
}

void CalculatorGUI::copyLineEdit()
{
    lineEdit->copy();
}

void CalculatorGUI::pasteLineEdit()
{
    lineEdit->paste();
}

void CalculatorGUI::copyTextBrowser()
{
    textBrowser->copy();
}

void CalculatorGUI::clearLineEdit()
{
    lineEdit->clear();
}

void CalculatorGUI::clearTextBrowser()
{
    textBrowser->clear();
}

void CalculatorGUI::selectAllLineEdit()
{
    lineEdit->selectAll();
}

void CalculatorGUI::selectAllTextBrowser()
{
    textBrowser->selectAll();
}

bool CalculatorGUI::focusOnLineEdit()
{
    if(lineEdit->hasFocus())
        return true;

    return false;
}

bool CalculatorGUI::focusOnTextBroswer()
{
    if(textBrowser->hasFocus())
        return true;

    return false;
}
