#include "listdialog.h"
#include "editdialog.h"
#include "listdialog.ui"

ListDialog::ListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListDialog)
{
    ui->setupUi(this);

    connect( ui->addButton, SIGNAL(clicked()) , this, SLOT(addItem()));
    connect( ui->editButton, SIGNAL(clicked()), this, SLOT(editItem()));
    connect( ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
}



ListDialog::~ListDialog()
{
    delete ui;
}

void ListDialog::addItem()
{
    EditDialog dlg(this);

    if(dlg.exec() == Qt::)
        ui->list->addItem(dlg.name() + " -- " + dlg.number());
}

void ListDialog::deleteItem()
{
    delete ui->list->currentItem();
}

void ListDialog::editItem()
{
    if( !ui->list->currentItem()) //check if current item != null pointer
        return;

    QStringList parts = ui->list->currentItem()->text().split("--");
    EditDialog dlg(this);

    dlg.setName(parts[0].trimmed());
    dlg.setNumber(parts[1].trimmed());

    if(dlg.exec() == Qt::Accepted)
        ui->list->currentItem()->setText( dlg.name() + " -- " + dlg.number());
}
