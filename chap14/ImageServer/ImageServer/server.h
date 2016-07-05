#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Server : public QTcpServer
{
public:
    Server();

protected:
    void incomingConnection(qintptr descriptor) Q_DECL_OVERRIDE;
};

#endif // SERVER_H
