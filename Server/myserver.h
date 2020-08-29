#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    MyServer();
    ~MyServer();

    QTcpSocket* socket;
    QByteArray data;
    QJsonDocument doc;
    QJsonObject obj;
    QJsonParseError docErr;
    QJsonArray docArr;

public slots:
    void startServer();
    void incomingConnection(int socketDescriptor);
    void sockReady();
    void sockDisc();
};

#endif // MYSERVER_H
