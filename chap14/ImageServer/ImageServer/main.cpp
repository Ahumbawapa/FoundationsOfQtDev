#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    if(!server.listen(QHostAddress::Any, 22222))
    {
        qCritical("Cannot listen to port 9876.");
        return 1;
    }
    else
    {
        qDebug() << QString("Server listen on %1: %2")
                    .arg(server.serverAddress().toString())
                    .arg(server.serverPort())
                    .toStdString().c_str();
    }

    if(server.isListening())
        qDebug() << "Listining...";

    return a.exec();
}
