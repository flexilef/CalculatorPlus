#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QTextBrowser>
#include <QVBoxLayout>

#include "include/Calculator.h"

class CalculatorGUI : public QWidget
{
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = 0);
    ~CalculatorGUI();

    void setRadiansMode();
    void setDegreesMode();

private:
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    Calculator calc;

public slots:
    void handleLineEdit();
};

#endif // CALCULATORGUI_H
