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
    void copyLineEdit();
    void copyTextBrowser();
    void pasteLineEdit();
    void clearLineEdit();
    void clearTextBrowser();
    void selectAllLineEdit();
    void selectAllTextBrowser();
    bool focusOnLineEdit();
    bool focusOnTextBroswer();

private:
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    Calculator calc;
    std::vector<QString> history;
    int historyIndex;

protected:
    bool eventFilter(QObject *, QEvent *);
public slots:
    void handleLineEdit();
};

#endif // CALCULATORGUI_H
