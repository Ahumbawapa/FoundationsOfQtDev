#include <iostream>
#include "myclass.h"

int main(int argc, char **argv)
{
    MyClass *a, *b, *c;

    a = new MyClass("foo");
    b = new MyClass("ba-a-ar");
    c = new MyClass("baz");

    std::cout << a->text() << "(" << a->getLengthOfText() << ")" << std::endl;
    a->setText(b->text());
    std::cout << a->text() << "(" << a->getLengthOfText() << ")" << std::endl;

    int result = a->getLengthOfText() - c->getLengthOfText();

    delete a;
    delete b;
    delete c;

    return result;
}
