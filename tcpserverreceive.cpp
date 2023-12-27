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
    const int values_count = 20; // Number of values for both current and voltage
    const int total_values = values_count * 2; // Total number of values (10 current + 10 voltage)
    // Extract current and voltage values into QList<double>
    QList<double> current_values;
    QList<double> voltage_values;
    for (QTcpSocket *socket : qAsConst(clientSockets)) {
        if (socket->bytesAvailable() >= sizeof(double) * total_values) {
            QByteArray data = socket->read(sizeof(double) * total_values);

            if (data.size() == sizeof(double) * total_values) {
                double received_values[total_values];

                memcpy(&received_values, data.constData(), sizeof(double) * total_values);



                for (int i = 0; i < values_count; ++i) {
                    double current = round(received_values[i] * 100.0) / 100.0;
                    double voltage = round(received_values[values_count + i] * 100.0) / 100.0;
                    current_values.append(current);
                    voltage_values.append(voltage);
                    qInfo() << current_values[i];


                }
            } else {
                qInfo() << "Incomplete data received";
            }
            emit messageReceived(current_values, voltage_values);
        }
    }
}



