#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

/**
 * @brief The tcpServerReceive class handles incoming TCP connections and data reception.
 */

class tcpServerReceive : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the tcpServerReceive class.
     * @param parent The optional parent object.
     */
    explicit tcpServerReceive(QObject *parent = nullptr);
    /**
     * @brief Starts the TCP server on the specified port.
     * @param port The port number on which the server should listen.
     * @return True if the server starts successfully; otherwise, false.
     *
     * This function starts the TCP server to listen for incoming connections
     * on the specified port. It returns true if the server starts successfully;
     * otherwise, it returns false.
     */
    Q_INVOKABLE bool startServer(quint16 port);
    /**
     * @brief Stops the TCP server and closes all client connections.
     *
     * This function stops the TCP server and closes all client connections
     * associated with it.
     */
    Q_INVOKABLE void stopServer();

signals:
    /**
     * @brief Signal emitted when complete data is received.
     * @param cooler_current List of cooler currents received.
     * @param cooler_voltage List of cooler voltages received.
     * @param detector_current List of detector currents received.
     * @param detector_voltage List of detector voltages received.
     */
    void messageReceived( QList<double> cooler_current,  QList<double> cooler_voltage, QList<double> detector_current,  QList<double> detector_voltage);

private slots:
    /**
     * @brief Slot called when a new client connection is established.
     */
    void onNewConnection();

    /**
     * @brief Slot for processing incoming data from connected clients.
     *
     * Reads and processes incoming data from client sockets. Extracts values
     * for cooler and detector currents/voltages. Emits 'messageReceived' signal
     * with parsed data. Logs received values for debugging.
     */
    void onReadyRead();

private:
    QTcpServer server;                ///< The TCP server object.
    QList<QTcpSocket*> clientSockets; ///< List of connected client sockets.

    /**
     * @brief Helper function to print the values in a QList<double>.
     * @param list The list of double values to print.
     *
     * This function prints the values in the provided list of double values.
     * It is a helper function used internally within this class.
     */
    void printLists(const QList<double> &list);

};


