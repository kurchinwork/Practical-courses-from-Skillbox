import QtQuick 2.5          // Изменили с 2.15 на 2.5
import QtQuick.Window 2.2   // Изменили с 2.15 на 2.2
import QtQuick.Controls 1.4 // Для Qt 5.5 используем Controls 1.4

Window {
    visible: true
    width: 500
    height: 250
    title: "QML Player"
    color: "#F2E9D8"

    Column {
        anchors.centerIn: parent

        ProgressBar {
            id: playerProgress
            width: 450
            minimumValue: 0
            maximumValue: 100
            value: 15
        }
    }

    Row {
        anchors.centerIn: parent

        Item {
            width: 1
            height: 99
        }

        Button {
            text: "⏪️"
            onClicked: console.log("Reverse")
        }

        Button {
            text: "▶️"
            onClicked: console.log("Play")
        }

        Button {
            text: "⏸️"
            onClicked: console.log("Pause")
        }

        Button {
            text: "⏹"
            onClicked: console.log("Stop")
        }

        Button {
            text: "⏩️"
            onClicked: console.log("Next")
        }

    }
}
