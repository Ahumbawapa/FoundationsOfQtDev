#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QMutex>

class QString;

class TextDevice
{
public:
    TextDevice();

    void write(const QString &);

private:
    int count;
    QMutex mutex;

};

#endif // TEXTDEVICE_H
