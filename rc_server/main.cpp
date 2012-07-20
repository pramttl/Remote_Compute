#include <QtCore/QCoreApplication>
#include <QHostAddress>
#include "rc_server.h"

static const quint16 DEFAULT_PORT = 7000;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    quint16 port = 0;
    bool ok = false;
    if (argc > 0)
    {
        port = QString(argv[0]).toInt(&ok);
    }
    if (!ok)
    {
        port = DEFAULT_PORT;
    }

    rc_server server;
    server.listen(QHostAddress::Any, port);

    return a.exec();
}
