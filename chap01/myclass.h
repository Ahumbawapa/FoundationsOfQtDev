#include <QObject>
#include <QString>


class MyClass : public QObject//Qt class names starts with a capital letter
{
public:
    MyClass( const QString &text, QObject *parent = 0);

    //names of methods starts with a lowercase letter using CamelCasing
    //getter and setter methods are named as the Property without m_
    //getter text()
    //setter setText()
    const QString& text() const;
    void setText(const QString &text);

    int getLengthOfText() const;

private:
    QString m_text;
};
