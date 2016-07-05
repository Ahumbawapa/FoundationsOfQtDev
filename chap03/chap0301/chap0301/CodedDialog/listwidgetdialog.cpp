#include "listwidgetdialog.h"
#include "ui_listwidgetdialog.h"

ListWidgetDialog::ListWidgetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListWidgetDialog)
{
    ui->setupUi(this);

    connect(this->ui->pushButtonMoveLeft, SIGNAL(clicked()), this, SLOT(moveLeft()));
    connect(this->ui->pushButtonMoveRight, SIGNAL(clicked()), this, SLOT(moveRight()));

    QStringList items;
    items << "Eins" << "Zwei" << "Drei" << "Vier"
          << "Fünf" << "Sechs"<< "Sieben" << "Acht"
          << "Neun" << "Zehn" << "Elf" << "Zwölf";

    this->ui->leftList->addItems(items);
}

ListWidgetDialog::~ListWidgetDialog()
{
    delete ui;
}

void ListWidgetDialog::moveLeft()
{
    if(ui->rightList->selectedItems().count() != 1)
        return;

    QListWidgetItem *item = ui->rightList->takeItem(ui->rightList->currentRow());

    ui->leftList->addItem(item);
}

void ListWidgetDialog::moveRight()
{
    if(ui->leftList->selectedItems().count() != 1)
        return;

    QListWidgetItem *item = ui->leftList->takeItem(ui->leftList->currentRow());
    ui->rightList->addItem(item);
}


