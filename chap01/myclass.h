#include <QObject>
#include <QString>


class MyClass : public QObject//Qt class names starts with a capital letter
{
    Q_OBJECT

public:
    MyClass( const QString &text, QObject *parent = 0);

    //names of methods starts with a lowercase letter using CamelCasing
    //getter and setter methods are named as the Property without m_
    //getter text()
    //setter setText()
    const QString& text() const;
    int getLengthOfText() const;

public slots:
    void setText(const QString &text);

signals:// functions declared in this section will not be implemented
    void textChanged(const QString &);

private:
    QString m_text;
};
