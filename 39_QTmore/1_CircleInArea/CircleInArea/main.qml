import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    id: root;
    minimumWidth: 640;
    minimumHeight: 480;
    visible: true
    title: "MainWindow"

    Rectangle {
        id: scene
        anchors.fill: parent

        Rectangle {
            id: leftRectangle
            x: 100
            y: 200
            color: "blue"
            width: 100
            height: 100
            border.color: "darkblue"
            border.width: 8
            radius: 5

            Text {
                id: leftRect
                anchors.centerIn: parent
                text: "Return"
                color: "lightblue"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                        bball.x = leftRectangle.x + 5
                }
            }
        }
        Rectangle {
            id: rightRectangle
            x: 500
            y: 200
            color: "blue"
            width: 100
            height: 100
            border.color: "darkblue"
            border.width: 8
            radius: 5

            Text {
                id: rightRect
                anchors.centerIn: parent
                text: "Move"
                color: "lightblue"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                      bball.x += 30
                    if (bball.x >= rightRectangle.x) {
                        bball.x = leftRectangle.x + 5
                    }
                }
            }
        }
        Rectangle {
            id: bball
            color: "grey"

            x: leftRectangle.x + 5
            y: leftRectangle.y + 5

            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            radius: 200
        }
    }
}
