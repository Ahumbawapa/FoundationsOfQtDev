#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person(const QString& name, const QString& number);

    const QString& name() const {return this->m_name;}
    const QString& number() const {return this->m_number;}


private:
    QString  m_name
            ,m_number;
};

#endif // PERSON_H
