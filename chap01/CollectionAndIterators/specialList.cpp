#include <QStringList>
#include <QtDebug>

int main2(int argc, char**argv)
{
    QStringList list;
    list << "foo" << "bar" << "baz";

    QString all = list.join(";");

    QStringList::const_iterator listIterator;

    for(listIterator = list.begin(); listIterator != list.end(); ++listIterator)
        qDebug() << *listIterator;

    qDebug() << "joined value: " << all;

    //replace a with oo in all strings of list
    list.replaceInStrings("a", "oo");

    for(listIterator = list.begin(); listIterator != list.end(); ++listIterator)
        qDebug() << *listIterator;

    list << all.split(";");

    qDebug() << "\n";
    for(listIterator = list.begin(); listIterator != list.end(); ++listIterator)
        qDebug() << *listIterator;

    return 0;
}
