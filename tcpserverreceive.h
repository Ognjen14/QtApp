#ifndef TCPSERVERRECEIVE_H
#define TCPSERVERRECEIVE_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
class tcpServerReceive : public QObject
{
    Q_OBJECT
public:
    explicit tcpServerReceive(QObject *parent = nullptr);
    Q_INVOKABLE bool startServer(quint16 port);
    Q_INVOKABLE void stopServer();
signals:
signals:
    void messageReceived(const double current, const double voltage);

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QTcpServer server;
    QList<QTcpSocket*> clientSockets;
};

#endif // TCPSERVERRECEIVE_H
