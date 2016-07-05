#ifndef CODEDDIALOG_H
#define CODEDDIALOG_H

#include <QDialog>

class CodedDialog : public QDialog
{
    Q_OBJECT

public:
    CodedDialog(QWidget *parent = 0);
    ~CodedDialog();
};

#endif // CODEDDIALOG_H
