#include "person.h"
#include <QHash>

Person::Person(const QString& name, const QString& number)
{
    this->m_name = name;
    this->m_number = number;
}

bool operator== (const Person &a, const Person &b)
{
    return (a.name() == b.name()) && (a.number() == b.number());
}

uint qHash(const Person &key)
{
    return qHash(key.name()) ^ qHash(key.number());
}
