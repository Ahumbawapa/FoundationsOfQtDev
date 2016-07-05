#include "codeddialog.h"
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QGridLayout>
#include <QPushButton>

CodedDialog::CodedDialog(QWidget *parent)
    : QDialog(parent)
{
    //create the labels - not visible in Dialog
    QGroupBox   *groupBox = new QGroupBox("GroupBox");
    QLabel      *label    = new QLabel("Supercalifragilisticexpialidocious");
    QLineEdit   *lineEdit = new QLineEdit;
    QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    //add layouts that include the widgets
    QHBoxLayout *hLayout = new QHBoxLayout(groupBox); //layout affects the groupBox
    hLayout->addWidget(label);
    hLayout->addWidget(lineEdit);

    //add some buttons to a grid layout
    QGroupBox *buttonGroupBox = new QGroupBox("Buttons in Grid");
    QGridLayout gridLayout(buttonGroupBox);
    //                                          int row, int column, int height = 1, int width = 1);
    gridLayout.addWidget(new QPushButton("Button01"),0, 0, 1, 2);
    gridLayout.addWidget(new QPushButton("Button02"), 1, 0);
    gridLayout.addWidget(new QPushButton("Button03"),1, 1);

    QVBoxLayout *vLayout = new QVBoxLayout(this); //Layout for the dialog itself
    vLayout->addWidget(groupBox);
    vLayout->addStretch(); //similar to a spacer in Designer
    vLayout->addWidget(buttonGroupBox);
    vLayout->addStretch();
    vLayout->addWidget(buttons);

    //setting policies (Richtlinien) for size
    QSizePolicy policy = label->sizePolicy();
    policy.setHorizontalStretch(3);
    label->setSizePolicy(policy);

    policy = lineEdit->sizePolicy();
    policy.setHorizontalStretch(1);
    lineEdit->setSizePolicy(policy);
}

CodedDialog::~CodedDialog()
{

}
