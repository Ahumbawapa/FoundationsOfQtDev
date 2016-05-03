#include <QtDebug>
#include <QString>

int main1 (int argc, char **argv)
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
    {
        int value = javaIter.next(); //next method returns current item and moves iterator to next item
        //javaIter.setValue(value); //compile error iterator has no member named setvalue - is  constant
        qDebug() << value; //next method returns current item and moves iterator to next item
    }

    //STL-like iteration
    QList<int>::const_iterator stlIterator;
    for(stlIterator = intList.begin(); stlIterator != intList.end(); ++stlIterator)
    {
        //(*stlIterator) = (*stlIterator) * 2;//compile error. iterator is read-only!
        qDebug() << (*stlIterator);
    }

    //mutable iterators to change list entries
    QMutableListIterator<int> mutJavaIter(intList);
    while(mutJavaIter.hasNext())
    {
        int value = mutJavaIter.next() + 1;
        mutJavaIter.setValue(value);//set value should not used before next()
        qDebug() << value;
    }

    QList<int>::Iterator mutStlIter;
    for(mutStlIter = intList.begin(); mutStlIter != intList.end(); ++mutStlIter)
    {
        (*mutStlIter) = (*mutStlIter)*2;
        qDebug() << (*mutStlIter);
    }

    //get list values with index operator
    int sum  = intList[0] + intList[1];
    qDebug() << sum;

    //appding items
    list << "first";
    list.append("second");
    list.prepend("third");
    list.insert(1, "fourth");
    list.insert(4, "fifth");

    QList<QString>::const_iterator stringListIterator;
    for(stringListIterator = list.begin(); stringListIterator != list.end(); ++stringListIterator)
    {
        qDebug() << *stringListIterator;
    }



    return 0;
}
