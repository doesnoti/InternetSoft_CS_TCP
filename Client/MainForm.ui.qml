import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    width: 320
    height: 200
    property alias label1: label1

    property alias button1: button1
    property alias button2: button2

    Button {

        id: button1
        x: 40
        y: 150
        width: 100
        height: 40
        text: "Connect"
    }

    Button {
        id: button2
        x: 180
        y: 150
        width: 100
        height: 40
        text: qsTr("Send")
    }

    Label {
        id: label1
        x: 20
        y: 20
        width: 280
        height: 100
        text: qsTr("Hello, client!")
        textFormat: Text.PlainText
    }
}
