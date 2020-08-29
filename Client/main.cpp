#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "myclient.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MyClient myClient;

    QQmlContext *context = engine.rootContext();
    context->setContextProperty ("myClient", &myClient);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
