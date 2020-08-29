#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>

class MyClient : public QObject
{
    Q_OBJECT

public:
    explicit MyClient(QObject *parent = 0);

    QTcpSocket *socket;
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray objArr;
    QJsonParseError docErr;

signals:
    void sendToQml(QString data);

public slots:
    void sockReady();
    void sockDisc();
    void connectedClient();
    void sendToSerever();

};

#endif // MYCLIENT_H
