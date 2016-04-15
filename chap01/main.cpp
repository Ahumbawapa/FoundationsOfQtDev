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

    qDebug() << QString::fromStdString(a->text()) << "(" << a->getLengthOfText() << ")";
    a->setText(b->text());
    qDebug() << QString::fromStdString(a->text()) << "(" << a->getLengthOfText() << ")" << std::endl;

    return  a->getLengthOfText() - c->getLengthOfText();

}
