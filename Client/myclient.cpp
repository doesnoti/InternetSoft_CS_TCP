#include "myclient.h"

MyClient::MyClient(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
        connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
        connect(socket, SIGNAL(diconnected()), this, SLOT(sockDisc()));
}

void MyClient::sockReady()
{
    if (socket->waitForConnected(500))
    {
        doc = QJsonDocument::fromJson( socket->readAll(), &docErr);

        if (docErr.errorString().toInt() == QJsonParseError::NoError)
        {
            obj = doc.object();

            if ( (obj.value("type").toString() == "connect") &&
            (obj.value("status").toString() == "yes") )
            {
                emit sendToQml("You are connected");
            }
            else
            {
                if ( obj.value("result").toString() != "" )
                {
                    emit sendToQml(obj.value("result").toString());
                }
                else
                {
                    emit sendToQml("Incorrect connection");
                }
            }
        }
        else
        {
            emit sendToQml("Format error: " + docErr.errorString());
        }
    }
}

void MyClient::sockDisc()
{
    socket->deleteLater();
}

void MyClient::connectedClient()
{
    socket->connectToHost("127.0.0.1", 111);
}

void MyClient::sendToSerever()
{
    if(socket->isOpen())
    {
        socket->write("{\"data\": [ {\"rectDescription1\":\"10, 10, 450, 230\"},{\"rectDescription2\":\"50,12,40,204\"}]}");
        socket->waitForBytesWritten(500);
    }
    else
    {
        emit sendToQml("No connection");
    }
}
