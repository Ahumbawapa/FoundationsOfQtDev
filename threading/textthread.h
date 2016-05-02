#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QString>
#include <QThread>


class TextThread : public QThread
{
public:
    TextThread(const QString &text);

    void run();

private:
    QString m_text;
};



#endif // TEXTTHREAD_H
