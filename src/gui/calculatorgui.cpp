#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

#include "include/gui/calculatorgui.h"

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

    if(isCommand(input))
    {
        runCommand(input);
    }
    else
    {
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
        historyIndex = history.size();
    }

    lineEdit->clear();
}

bool CalculatorGUI::isCommand(const QString &command)
{
    if(command == "?radians")
        return true;
    else if(command == "?degrees")
        return true;
    else if(command == "?memory")
        return true;
    else if(command == "?clearmemory")
        return true;
    else if(command == "?commands")
        return true;

    return false;
}

void CalculatorGUI::runCommand(const QString &command)
{
    textBrowser->append(command);

    if(command == "?radians")
    {
        calc.setAngleMode(MathUtil::RADIANS);
        textBrowser->append("Radians Mode");
        emit statusBarEvent("Mode: radians");
        emit checkRadiansEvent();
    }
    else if(command == "?degrees")
    {
        calc.setAngleMode(MathUtil::DEGREES);
        textBrowser->append("Degrees Mode");
        emit statusBarEvent("Mode: degrees");
        emit checkDegreesEvent();
    }
    else if(command == "?memory")
    {
        std::vector<std::string> vars = calc.getVariables();
        int length = vars.size();

        textBrowser->append("Variables = Values");

        for(int i=0; i<length; i++)
        {
            textBrowser->append(QString::fromStdString(vars[i]) + " = " +
                                QString::number(calc.getValueFromVariable(vars[i])));
        }
    }
    else if(command == "?clearmemory")
    {
        calc.clearMemory();
        textBrowser->append("Memory cleared");

    }
    else if(command == "?commands")
    {
        textBrowser->append("List of Commands \n"
                            "?commands - lists commands \n"
                            "?radians - switches to radians mode \n"
                            "?degrees - switches to degrees mode \n"
                            "?memory - lists stored variables \n"
                            "?clearmemory - clears stored variables");
    }

    textBrowser->append("");
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
