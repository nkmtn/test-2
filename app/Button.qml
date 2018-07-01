import QtQuick 2.0
//import "qrc:/"

Rectangle {
    width: 200
    height: 40
    color: "blue"

    radius: 10

    property alias text: text.text
    signal clicked

    Text {
        id: text
        text: "Button"
        anchors.centerIn: parent
        font.pointSize: 20
        color: "white"
    }

    MouseArea {
        anchors.fill: parent
        onPressed: parent.color = "white"
        onReleased: parent.color = "blue"
        onClicked: parent.clicked()
    }
}
