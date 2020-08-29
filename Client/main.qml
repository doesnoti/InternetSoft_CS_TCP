import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 320
    height: 200
    title: qsTr("Client")

    Connections{
        target: myClient
        onSendToQml: {
            label1.text = data
        }
    }

    MainForm {
        anchors.fill: parent

        button1.onClicked: myClient.connectedClient()
        button2.onClicked: myClient.sendToSerever()

        label1 {
            id: label1
        }
    }
}
