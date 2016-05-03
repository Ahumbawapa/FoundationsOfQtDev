#include "textdevice.h"
#include <QMutexLocker>
#include <QString>
#include <QDebug>

TextDevice::TextDevice()
{
    count = 0;
}


void TextDevice::write(const QString & text)
{
    //QMutexLocker locks the mutex as soon it is constructed
    // and unlocks it when it is destructed
    QMutexLocker locker(&mutex);
    qDebug() << QString("Call %1: %2").arg(count++).arg(text);
}

