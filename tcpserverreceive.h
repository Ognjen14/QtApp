#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "string.h"
class tcpServerReceive : public QObject
{
    Q_OBJECT

public:
    explicit tcpServerReceive(QObject *parent = nullptr);
    Q_INVOKABLE bool startServer(quint16 port);
    Q_INVOKABLE void stopServer();
signals:
signals:
    void messageReceived( QList<double> cooler_current,  QList<double> cooler_voltage, QList<double> detector_current,  QList<double> detector_voltage);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer server;
    QList<QTcpSocket*> clientSockets;
    void printLists(const QList<double> &list);
};


