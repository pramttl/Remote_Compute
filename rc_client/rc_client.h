#ifndef RC_CLIENT_H
#define RC_CLIENT_H

#include <QObject>
#include <QByteArray>


class QBuffer;
class QTcpSocket;

class rc_client: public QObject
{
    Q_OBJECT

public:
    rc_client(QObject *parent=0);
    ~rc_client();
    void sendMessage(int NUMBER);
    void toggleConnection();

private slots:
    void setConnected();
    void setDisconnected();

public slots:
    void receiveMessage();

public:
    QBuffer*		buffer;
    QTcpSocket*		socket;
};


#endif // RC_CLIENT_H
