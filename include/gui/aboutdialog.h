#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QLabel>

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private:
    QLabel* title;
    QLabel* version;
    QLabel* body;
    QLabel* image;
    QLabel* copyright;

};

#endif // ABOUTDIALOG_H
