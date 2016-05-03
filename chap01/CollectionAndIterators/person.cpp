#include "person.h"
#include <QHash>

Person::Person(const QString& name, const QString& number)
{
    this->m_name = name;
    this->m_number = number;
}


