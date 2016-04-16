#include <QtDebug>
#include <QObject>
#include <QString>
#include "myclass.h"

int main(int argc, char **argv)
{
    QObject parent; //is responsible for deleting the child items
    MyClass *a, *b, *c;

    a = new MyClass("foo");
    b = new MyClass("ba-a-ar");
    c = new MyClass("baz");

    QObject::connect( a, SIGNAL(textChanged(const QString&)),
                      b, SLOT(setText(const QString&)) );
    QObject::connect( b, SIGNAL(textChanged(const QString&)),
                      c, SLOT(setText(const QString&)) );
    QObject::connect( c, SIGNAL(textChanged(const QString&)),
                      b, SLOT(setText(const QString&)) );

    qDebug() << a->text() << "(" << a->getLengthOfText() << ")";
    a->setText(b->text());
    qDebug() << a->text() << "(" << a->getLengthOfText() << ")";

    return  a->getLengthOfText() - c->getLengthOfText();

}
