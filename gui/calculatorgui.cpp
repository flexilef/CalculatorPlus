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
