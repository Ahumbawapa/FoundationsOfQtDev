#include <QObject>
#include <string>
using std::string;

class MyClass : public QObject//Qt class names starts with a capital letter
{
public:
    MyClass( const string &text, QObject *parent = 0);

    //names of methods starts with a lowercase letter using CamelCasing
    //getter and setter methods are named as the Property without m_
    //getter text()
    //setter setText()
    const string& text() const;
    void setText(const string &text);

    int getLengthOfText() const;

private:
    string m_text;
};
