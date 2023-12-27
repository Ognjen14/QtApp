#include "tcpserverreceive.h"

tcpServerReceive::tcpServerReceive(QObject *parent)
    : QObject{parent}
{
    connect(&server, &QTcpServer::newConnection, this, &tcpServerReceive::onNewConnection);
}

bool tcpServerReceive::startServer(quint16 port)
{
    if (!server.listen(QHostAddress::Any, port)) {
        return false;
    }
    return true;
}

void tcpServerReceive::stopServer()
{
    server.close();
    for (QTcpSocket *socket : qAsConst(clientSockets)) {
        socket->close();
        socket->deleteLater();
    }
    clientSockets.clear();
}

void tcpServerReceive::onNewConnection()
{
    QTcpSocket *newClient = server.nextPendingConnection();
    if (newClient) {
        clientSockets.append(newClient);
        connect(newClient, &QTcpSocket::readyRead, this, &tcpServerReceive::onReadyRead);
    }
}

void tcpServerReceive::onReadyRead()
{
    for (QTcpSocket *socket : qAsConst(clientSockets)) {
        if (socket->bytesAvailable() >= sizeof(double) * 2) {
            QByteArray data = socket->read(sizeof(double) * 2);

            if (data.size() == sizeof(double) * 2) {
                double received_values[2];

                memcpy(&received_values, data.constData(), sizeof(double) * 2);

                double value1 = received_values[0];
                double value2 = received_values[1];

                value1 = round(value1 * 100.0) / 100.0;
                value2 = round(value2 * 100.0) / 100.0;
                emit messageReceived(value1, value2);
            } else {
                qInfo() << "Incomplete data received";
            }
        }
    }
}

