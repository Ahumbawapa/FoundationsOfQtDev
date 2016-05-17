#include "listdialog.h"
#include "editdialog.h"

ListDialog::ListDialog()
    :QDialog()
{
    ui.setupUi(this);

    connect(    ui.pushButtonAdd, SIGNAL(clicked())
            ,   this        , SLOT(addItem()));
    connect(    ui.pushButtonEdit, SIGNAL(clicked())
            ,   this        , SLOT(editItem()));
    connect(    ui.pushButtonDelete, SIGNAL(clicked())
            ,   this        , SLOT(deleteItem()));

}

void ListDialog::addItem()
{
    EditDialog dlg(this);

    if(dlg.exec() == QDialog::Accepted)
        ui.list->addItem(dlg.name() + " -- " + dlg.number());
}

void ListDialog::deleteItem()
{
    delete ui.list->currentItem();
}

void ListDialog::editItem()
{
    //check if valid item is selected
    if(!ui.list->currentItem())
        return;

    QStringList parts = ui.list->currentItem()->text().split("--");

    EditDialog dlg(this);
    dlg.setName(parts[0].trimmed());
    dlg.setNumber(parts[1].trimmed());

    if(QDialog::Accepted == dlg.exec())
        ui.list->currentItem()->setText(dlg.name() + " -- " + dlg.number());
}
