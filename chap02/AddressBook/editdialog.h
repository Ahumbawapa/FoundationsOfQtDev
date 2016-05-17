#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include "ui_editdialog.h"

class EditDialog : public QDialog
{
public:
    EditDialog(QWidget *parent = 0);

    const QString name() const;
    void  setName(const QString&);

    const QString number() const;
    void  setNumber(const QString&);

private:
    Ui::EditDialog ui;
};

#endif // EDITDIALOG_H
