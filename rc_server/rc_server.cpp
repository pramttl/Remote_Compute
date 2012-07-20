#include <QtCore/QCoreApplication>

#include <string>

#include "rc_server.h"
#include <QBuffer>
#include <QTcpSocket>
#include <QDebug>
#include <QProcess>

#include "debugging_functions.h"
#include "utility_functions.h"


rc_server::rc_server(QObject* parent) : QTcpServer(parent)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(addConnection()));
}

rc_server::~rc_server()
{
}

void rc_server::addConnection()
{
    QTcpSocket* connection = nextPendingConnection();
    qDebug() << "<rc_server>: I have accepted a new connection request.";
    connections.append(connection);
    QBuffer* buffer = new QBuffer(this);
    buffer->open(QIODevice::ReadWrite);

    /* buffers is of <QHash> datatype, ie. with connection object used as the key.
     This is a good idea to store information from different connected clients in an organized way.*/
    buffers.insert(connection, buffer);

    connect(connection, SIGNAL(disconnected()), SLOT(removeConnection()));
    connect(connection, SIGNAL(readyRead()),	SLOT(receiveMessage()));
}

void rc_server::removeConnection()
{
    /* static_cast: used to perform conversions between pointers to related classes,
    not only from the derived class to its base, but also from a base class to its derived. */
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());

    QBuffer* buffer = buffers.take(socket);
    buffer->close();
    buffer->deleteLater();
    connections.removeAll(socket);
    socket->deleteLater();
}

void rc_server::receiveMessage()
{
    qDebug() << "<rc_server>: I have received some message from the client";
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    QByteArray MSG_DATA;

    // 'buffers' is a QHash object. 'buffer' is assigned data for the corresponding client socket.
    QBuffer* buffer = buffers.value(socket);

    (*buffer).seek(0);
    MSG_DATA = socket->readAll();


    if (MSG_DATA.size() == 5)
    {
        Debug_Byte_Array("Input Received",MSG_DATA);

        int remote_input = Hex_Bytes_BE_to_Integer(MSG_DATA.mid(1,4));

        ////////////////////////////////////////////////////////////////////////////////////////
        /// THE CURRENT PROCESS CALLS ANOTHER EXE OR OBJECT APPLICATION HERE, AS A CHILD PROCESS

        // The Called PROCESS is nothing but another application, .exe (in Windows) or .o (in Linux), which returns the output in the exit code.
        // Please Note: For this application, It is important that the executable finally puts the computed result in the exit code which is an integer.
        /// //TODO: To look for better ways of inter-process communication via Channels, so that making use of the Exit Code for storing the result is avoided.

        // Call the console application, that shall carry out the remote computation over here.

         QObject *parent;
         QString program = "program/program";

         QStringList arguments;
         QString num = int_to_QString(remote_input);
         arguments << num;

         QProcess *computingProcess = new QProcess(parent);
         computingProcess->start(program, arguments);
         computingProcess->waitForStarted();
         qDebug() << "<rc_server>: " << "Computing Program Started";

         // computingProcess->waitForReadyRead();
         // QByteArray computingProcess_out_bytes = computingProcess->readAll();
         // qDebug() << "computingProcess_out_bytes:" << computingProcess_out_bytes.toHex();

         computingProcess->waitForFinished();
         int computingProcess_output = computingProcess->exitCode();
         qDebug() << "computingProcess_output: " << computingProcess_output;
         qDebug() << "<rc_server>: " << "Computing Program Complete";
        ////////////////////////////////////////////////////////////////////////////////////////



        QByteArray Computed_Output_Bytes = int_to_qb_array_BE(computingProcess_output,4);


        /* Writing the variable Computed_Output_Bytes to the connection (socket object) for each connection in conections ie.
        sending back a response message to the clients. */
        foreach (QTcpSocket* connection, connections)
        {
            connection->write(Computed_Output_Bytes);
        }
        qDebug() << "<rc_server>: I have sent a response to all the requesting Clients.";
    }

}
