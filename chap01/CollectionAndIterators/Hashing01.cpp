//Hashing01.cpp
#include "person.h"
#include "QString"
#include "QHash"
#include <QDebug>
#include <QSet>



bool operator== (const Person &a, const Person &b)
{
    return (a.name() == b.name()) && (a.number() == b.number());
}

uint qHash(const Person &key)
{
    uint nameHash = qHash(key.name());
    uint numberHash = qHash(key.number());
    uint returnHash = nameHash ^ numberHash;

    return returnHash;
}




int main(int argc,   char** argv)
{
    QHash<Person, int> hash;

    hash[ Person("Anders", "8447070")] = 10;
    hash[ Person("Micke", "7728523")] = 20;

    qDebug() << "Hash.value:" << hash.value(Person("Anders", "8447070"));
    qDebug() << "Hash.value:" << hash.value(Person("Anders", "8447071"));
    qDebug() << "Hash.value:" << hash.value(Person("Micke", "7728523"));
    qDebug() << "Hash.value:" << hash.value(Person("Micky", "7728523"));

    //for checking if keys are valid use a set
    QSet<QString> set;

    set << "Ada" << "C++" << "Ruby";

    for(QSet<QString>::ConstIterator ii = set.begin(); ii != set.end(); ++ii)
        qDebug() << *ii;

    if(set.contains("Fortran"))
        qDebug() << "Fortran is in the set";
    else
        qDebug() << "Fortran is out";

    if(set.contains("C++"))
        qDebug() << "c++ is in the set";
    else
        qDebug() << "c++ is out";


    //MultiHashes & Multimaps stores a list of items for one key
    QMultiMap<QString, int> multiMap;
    multiMap.insert("First", 10);
    multiMap.insert("First", 20);
    multiMap.insert("Second", 30);

    //use a set to get a key list and iterate over the keys
    QSet<QString> keys = QSet<QString>::fromList(multiMap.keys());

    foreach(QString key, keys)
        foreach(int value, multiMap.values(key))
            qDebug() << key << ": "  << value;


    //using an iterator to find all values of a key
    QMultiMap<QString, int>::ConstIterator ci = multiMap.find("First");
    while(ci != multiMap.end() && ci.key() == "First")
    {
        qDebug() << ci.value();
        ++ci;
    }

    //usíng a MultiHash - arbitrary key order


    qDebug() << "Using a QMultiHash";

    QMultiHash<QString, int> multi;
    multi.insert("Fourth", 10);
    multi.insert("Fourth", 20);
    multi.insert("Fifth", 30);

    QSet<QString> keys2 = QSet<QString>::fromList(multi.keys());

    foreach(QString key, keys2)
        foreach(int value, multi.values(key))
            qDebug() << key << ": " << value;

    QMultiHash<QString, int>::ConstIterator ci2 = multi.find("Fourth");

    while(ci2 != multi.end() && ci2.key() == "Fourth")
    {
        qDebug() << ci2.value();
        ++ci2;
    }

    return 0;
}
