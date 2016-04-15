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

    qDebug() << a->text() << "(" << a->getLengthOfText() << ")";
    a->setText(b->text());
    qDebug() << a->text() << "(" << a->getLengthOfText() << ")";

    return  a->getLengthOfText() - c->getLengthOfText();

}
