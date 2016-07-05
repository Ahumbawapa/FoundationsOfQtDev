#include "serverthread.h"

#include <QTime>
#include <QDir>
#include <QTcpSocket>
#include <QBuffer>
#include <QImageWriter>

ServerThread::ServerThread(int descriptor, QObject *parent)
    : QThread(parent)
{
    qDebug() << QString("Creating ServerThread with id %1").arg(descriptor).toStdString().c_str();
    m_descriptor = descriptor;
}


QImage ServerThread::randomImage()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QDir dir("images");
    dir.setFilter(QDir::Files);

    QFileInfoList entries = dir.entryInfoList();

    if(entries.size() == 0)
    {
        qDebug("No images to show!");
        return QImage();
    }

    return QImage( entries.at(qrand() % entries.size()).absoluteFilePath());
}


void ServerThread::run()
{
    QTcpSocket socket;

    if(!socket.setSocketDescriptor(m_descriptor))
    {
        qDebug("Socket error!");
        return;
    }

    QBuffer buffer;
    QImageWriter writer(&buffer, "PNG");
    writer.write(randomImage());

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_6);
    stream << (quint32)buffer.data().size();
    data.append(buffer.data());

    socket.write(data);

    socket.disconnectFromHost();
    socket.waitForDisconnected();
}
