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
    const int values_count = 20; // Total number of values for each type

    for (QTcpSocket *socket : qAsConst(clientSockets)) {
        if (socket->bytesAvailable() >= sizeof(double) * values_count * 4) { // Total size for all four data types
            QByteArray data = socket->read(sizeof(double) * values_count * 4); // Read all four data types

            if (data.size() == sizeof(double) * values_count * 4) {
                double received_values[values_count * 4];
                memcpy(&received_values, data.constData(), sizeof(double) * values_count * 4);

                QList<double> cooler_current;
                QList<double> cooler_voltage;
                QList<double> detector_current;
                QList<double> detector_voltage;

                for (int i = 0; i < values_count; ++i) {
                    cooler_current.append(round(received_values[i] * 100.0) / 100.0);
                    cooler_voltage.append(round(received_values[values_count + i] * 100.0) / 100.0);
                    detector_current.append(round(received_values[2 * values_count + i] * 100.0) / 100.0);
                    detector_voltage.append(round(received_values[3 * values_count + i] * 100.0) / 100.0);
                }

                emit messageReceived(cooler_current, cooler_voltage, detector_current, detector_voltage);
                qDebug() << "cooler_current:";
                printLists(cooler_current);

                qDebug() << "cooler_voltage:";
                printLists(cooler_voltage);

                qDebug() << "detector_current:";
                printLists(detector_current);

                qDebug() << "detector_voltage:";
                printLists(detector_voltage);
            } else {
                qInfo() << "Incomplete data received";
            }
        }
    }
}
void tcpServerReceive::printLists(const QList<double>& list) {
    for (const auto& value : list) {
        qDebug() << value;
    }
}




