#include <QtDebug>
#include <QString>

int main (int argc, char **argv)
{
    QList<QString> list;
    list << "first" << "second" << "third";

    foreach(QString s, list)
        qDebug() << s;

    QList<int> intList;
    intList << 23 << 27 << 52 << 52;

    //java like iterations
    QListIterator<int> javaIter(intList);
    while(javaIter.hasNext())
        qDebug() << javaIter.next(); //next method returns current item and moves iterator to next item

    //STL-like iteration
    QList<int>::const_iterator stlIterator;
    for(stlIterator = intList.begin(); stlIterator != intList.end(); ++stlIterator)
        qDebug() << (*stlIterator);

    return 0;
}
