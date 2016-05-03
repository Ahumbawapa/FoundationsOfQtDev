#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QString>
#include <QThread>
#include "textdevice.h"

class TextThread : public QThread
{
public:
    TextThread(const QString &text, TextDevice* device);
    ~TextThread();

    void run();

private:
    TextDevice* m_textDevice;
    QString m_text;
};



#endif // TEXTTHREAD_H
