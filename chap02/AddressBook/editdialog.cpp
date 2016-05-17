#include "editdialog.h"

EditDialog::EditDialog(QWidget *parent)
    :QDialog(parent)
{
    ui.setupUi(this);
}

const QString EditDialog::name() const
{
    return ui.lineEditName->text().replace("--", "").trimmed();
}

void EditDialog::setName(const QString &name)
{
    ui.lineEditName->setText(name);
}

const QString EditDialog::number() const
{
    return ui.lineEditNumber->text().replace("--", "").trimmed();
}

void EditDialog::setNumber(const QString &number)
{
    ui.lineEditNumber->setText(number);
}
