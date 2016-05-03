//Hashing01.cpp
#include "person.h"
#include "QString"
#include "QHash"

int main(int argc,   char** argv)
{
    QHash<Person, int> hash;

    hash[ Person("Anders", "8447070")] = 10;
    hash[ Person("Micke", "7728523")] = 20;




    return 0;
}
