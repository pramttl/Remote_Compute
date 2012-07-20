#ifndef RC_SERVER_H
#define RC_SERVER_H

#include <QTcpServer>
#include <QList>
#include <QHash>

class QBuffer;
class QTcpSocket;

class rc_server : public QTcpServer
{
    // Q_OBJECT macro enables to retrieve the Meta Object information that is associated with the object..
    Q_OBJECT

public:
    rc_server(QObject* parent = 0);
    ~rc_server();

private slots:
    void addConnection();
    void removeConnection();
    void receiveMessage();

private:
    // List of socket objects or connections.
    QList<QTcpSocket*> connections;

    // Dictionary whose values (Buffer Objects) are accessible using Socket Objects as keys.
    QHash<QTcpSocket*, QBuffer*> buffers;
};

#endif // RC_SERVER_H
