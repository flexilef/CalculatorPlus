#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QTextBrowser>
#include <QVBoxLayout>

#include "include/core/Calculator.h"

class CalculatorGUI : public QWidget
{
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = 0);
    ~CalculatorGUI();

    bool isCommand(const QString&);
    void runCommand(const QString&);

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

signals:
    void statusBarEvent(const QString&);
    void checkRadiansEvent();
    void checkDegreesEvent();
};

#endif // CALCULATORGUI_H
