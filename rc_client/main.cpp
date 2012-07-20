#include <QtCore/QCoreApplication>
#include <QDebug>
#include "rc_client.h"


int main(int argc, char* argv[])
{
    int NUMBER = atoi(argv[1]);
    QCoreApplication a(argc, argv);
    qDebug() << "\n1. SenoNet Console Application Instantiated";

    rc_client client;
    qDebug() << "2. Client Object Created";

    // client.show(); // Only Necessary in a GUI.

    // First Time Use to Establish Connection with Server.
    client.toggleConnection();
    qDebug() << "3. Connection Instantiation Request Issued";

    // To send our test Message Inbuilt into the code.
    client.sendMessage(NUMBER);
    qDebug() << "4. Message Sent to Server" << endl;

    return a.exec();
}
