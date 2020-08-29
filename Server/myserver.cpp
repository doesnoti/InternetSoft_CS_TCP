#include "myserver.h"

MyServer::MyServer(){}
MyServer::~MyServer(){}

void MyServer::startServer()
{
    if (this->listen(QHostAddress::Any, 111))
    {
        qDebug() << "Listening";
    }
    else
    {
        qDebug() << "Not listening";
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
        connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

    qDebug() << socketDescriptor << " Client connected";

    socket->write("{\"type\":\"connect\",\"status\":\"yes\"}");
    qDebug() << "Status send to client - connected";
}

void MyServer::sockReady()
{
    data = socket->readAll();
    qDebug() << "Data: " << data;

    doc = QJsonDocument::fromJson(data, &docErr);

    if (docErr.errorString().toInt() == QJsonParseError::NoError)
    {
        QByteArray strTemp;

        obj = doc.object();

        docArr = obj.value("data").toArray();

        for (int i = 0; i < docArr.count(); i++)
        {
            QJsonObject objTemp = docArr.at(i).toObject();
            if (objTemp.value("rectDescription2").toString() != "")
            {
                strTemp = objTemp.value("rectDescription2").toString().toUtf8();
            }
        }
        socket->write("{\"result\":\"" + strTemp + "\"}");
        socket->waitForBytesWritten(500);
    }
}

void MyServer::sockDisc()
{
    qDebug() << "Disconnected";
    socket->deleteLater();
}
