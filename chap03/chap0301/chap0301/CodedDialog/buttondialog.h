#ifndef BUTTONDIALOG_H
#define BUTTONDIALOG_H

#include<QDialog>


class ButtonDialog : public QDialog
{
    Q_OBJECT

public:
    ButtonDialog();

public slots:
    void buttonClicked();
    void buttonToggled();
private:
    QPushButton *clickButton;
    QPushButton *toggleButton;
};

#endif // BUTTONDIALOG_H
