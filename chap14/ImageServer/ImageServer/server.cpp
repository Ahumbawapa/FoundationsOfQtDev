#include "server.h"
#include "serverthread.h"

Server::Server()
    :QTcpServer()
{
    qDebug() << QString("ctor Server...").toStdString().c_str();
}

void Server::incomingConnection(qintptr descriptor)
{
    qDebug() << QString("Server::incomingConnection(%1)").arg(descriptor).toStdString().c_str();
    ServerThread *thread = new ServerThread(descriptor, this);

    connect( thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}
