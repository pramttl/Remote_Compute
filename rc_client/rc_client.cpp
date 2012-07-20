#include "rc_client.h"

#include <QTcpSocket>
#include <QBuffer>
#include <QHostAddress>
#include <QByteArray>
#include <QBitArray>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QtConcurrentRun>

#include "debugging_functions.h"
#include "utility_functions.h"

#include <iostream>

/// Our own Server
QString SERVER_IP = "localhost";
quint16 PORT = 7000;
int NUMBER = 4;

// Constructor for the SenoCAD class.
rc_client::rc_client(QObject *parent)
    : QObject(parent)
{
    buffer = new QBuffer(this);
    socket = new QTcpSocket(this);
    buffer->open(QIODevice::ReadWrite);

    /////////////////////
    /// SIGNALS & SLOTS
    /////////////////////
    connect(socket, SIGNAL(connected()), SLOT(setConnected()));
    // connect(socket, SIGNAL(disconnected()), SLOT(setDisconnected()));
    connect(socket, SIGNAL(readyRead()), SLOT(receiveMessage()));

    setDisconnected();
}

rc_client::~rc_client()
{
    buffer->close();
}

void rc_client::setConnected()
{
    qDebug() << "Connection With Server Established Successfully";
}

void rc_client::setDisconnected()
{
}

void rc_client::toggleConnection()
{
    QString SERVER_IP = "localhost";
    quint16 PORT = 7000;

    if (socket->state() == QAbstractSocket::UnconnectedState)
    {
        socket->connectToHost(SERVER_IP, PORT);
    }
    else
    {
        socket->disconnectFromHost();
    }
}

void rc_client::sendMessage(int NUMBER)
{

    QByteArray MESSAGE_BYTES = QByteArray::fromHex("00");
    MESSAGE_BYTES.append(int_to_qb_array_BE(NUMBER,4));
    socket->write(MESSAGE_BYTES);
}


void rc_client::receiveMessage()
{
    // extern void AsynchronusReceiver(QBuffer * buffer,QTcpSocket * socket);

    //// Starting a Concurrent Process, that runs in a new thread, so that it does not pause the event loop for long.
    //// Otherwise we will not be able to catch all data that arrives to the socket.
    // QFuture<void> future = QtConcurrent::run(AsynchronusReceiver,buffer,socket);

    QByteArray Computed_Response_Bytes = socket->readAll();
    int computed_sum = Hex_Bytes_BE_to_Integer(Computed_Response_Bytes);
    qDebug() << "computed_sum" << computed_sum;
    printf("The remotely computed sum equals: %d",computed_sum);
}
