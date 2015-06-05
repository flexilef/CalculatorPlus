#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QTextBrowser>
#include <QVBoxLayout>

class CalculatorGUI : public QWidget
{
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = 0);
    ~CalculatorGUI();

private:
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;

public slots:
    void handleLineEdit();
};

#endif // CALCULATORGUI_H
