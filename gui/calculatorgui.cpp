#include "calculatorgui.h"
#include <QEvent>
#include <QKeyEvent>

CalculatorGUI::CalculatorGUI(QWidget *parent) : QWidget(parent)
{
    historyIndex = 0;

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

bool CalculatorGUI::eventFilter(QObject *object, QEvent *event)
{
    if(object == lineEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *ke = static_cast<QKeyEvent *>(event);
            if(ke->key() == Qt::Key_Up)
            {
                if(!history.empty() && historyIndex>0)
                    lineEdit->setText(history[--historyIndex]);
                return true;
            }
            else if(ke->key() == Qt::Key_Down)
            {
                if(!history.empty() && historyIndex<history.size()-1)
                    lineEdit->setText(history[++historyIndex]);
                return true;
            }
        }
        return false;
    }
    return CalculatorGUI::eventFilter(object, event);
}

void CalculatorGUI::handleLineEdit()
{
    QString input = lineEdit->text();
    QString output;
    double result = 0;

    history.push_back(input);
    historyIndex++;
    calc.setInput(input.toStdString());
    calc.calculate();

    if(calc.getCalculatorState() == Calculator::ERRORSTATE)
    {
        output = QString::fromStdString(calc.getErrorMessage());
        calc.setCalculatorState(Calculator::DEFAULTSTATE);
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
