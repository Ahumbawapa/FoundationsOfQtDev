#include "buttondialog.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QLabel>


ButtonDialog::ButtonDialog()
{
    clickButton = new QPushButton("click me!", this);
    toggleButton = new QPushButton("Toggle me!", this);
    toggleButton->setCheckable(true);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(clickButton);
    hLayout->addWidget(toggleButton);



    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal);
    QPushButton *acceptButton = new QPushButton("ok");
    connect (acceptButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    buttonBox->addButton(acceptButton, QDialogButtonBox::AcceptRole);


    QLabel *labelOne = new QLabel("Label&1");
    QLabel *labelTwo = new QLabel("Label&2");
    QLineEdit *editOne = new QLineEdit;
    QLineEdit *editTwo = new QLineEdit;

    labelOne->setBuddy(editOne);
    labelTwo->setBuddy(editTwo);

    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(labelOne, 0,0);
    gridLayout->addWidget(editOne, 0, 1);
    gridLayout->addWidget(labelTwo, 1, 0);
    gridLayout->addWidget(editTwo, 1, 1);
    gridLayout->addItem(hLayout, 2,0,3,0);
    gridLayout->addWidget(buttonBox, 3,0,3,0);


    connect( clickButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect( toggleButton, SIGNAL(clicked()), this, SLOT(buttonToggled()));

}

void ButtonDialog::buttonClicked()
{
    QMessageBox::information(this, "Clicked!", "The button was clicked!");
}

void ButtonDialog::buttonToggled()
{
    QMessageBox::information(  this
                             , "Toggled!"
                             , QString("The button is %1").arg(toggleButton->isChecked()?"pressed" : "released"));
}
