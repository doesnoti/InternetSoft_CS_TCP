TEMPLATE = app

QT += qml quick \
   network core

CONFIG += c++11

SOURCES += main.cpp \
    myclient.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    myclient.h