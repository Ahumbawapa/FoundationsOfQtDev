//Mapping and Hashing

#include <QMap> //enable to keep items in key-value pairs.
#include <QtDebug>

int main4(int argc, char **argv)
{
    //   key    , value
    QMap<QString, int> map;
    map["first"]    = 1;
    map["second"]   = 2;
    map["third"]    = 3;

    //showing all key-value pairs on the debugging console
    foreach(QString key, map.keys())
        qDebug() << key << " = " << map[key];

    //directly iterate over the key/value pairs withh constIterator
    //saves one lookup per loop iteration

    QMap<QString, int>::ConstIterator ii;
    for(ii = map.constBegin(); ii != map.constEnd(); ++ii)
        qDebug() << ii.key() << " = " << ii.value();

    //access with [] force the list to insert items if they not exists
    int sum = map["third"] + map["fourth"]; //fourth is not existing -> will be created (with value 0)
    qDebug() << "Sum:" << sum;


    for(ii = map.constBegin(); ii != map.constEnd(); ++ii)
        qDebug() << ii.key() << " = " << ii.value();

    //use map.value() instead of [] to avoid inserting non existing items

    sum = map["third"] + map.value("fifth");
    qDebug() << "Sum: " << sum;


    for(ii = map.constBegin(); ii != map.constEnd(); ++ii)
        qDebug() << ii.key() << " = " << ii.value();


    return 0;



}
