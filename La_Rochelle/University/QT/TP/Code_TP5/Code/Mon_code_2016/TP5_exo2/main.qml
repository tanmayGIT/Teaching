import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2


ApplicationWindow {
    title: qsTr("Hello World")
    width: 400
    height: 400
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
   //     anchors.fill: parent


        //qlog("toto");


        Rectangle {
            id: afficheur
            width: 100
            height: 100
            //    color: "white"
            border.width: 2
            border.color: "blue"
           // anchors.centerIn: parent

            MouseArea {
               id: toto
                  anchors.fill:  afficheur
               acceptedButtons: Qt.RightButton | Qt.LeftButton
                hoverEnabled: true
                onClicked:  { afficheur.state='selection'}
    //                    qlog("toto");




            }

            states: [
                State {
                    name: "selection"
                    PropertyChanges {
                        target: afficheur
                        border.color:"red"
                        width: 300
                    }
                }
            ]

        }



    }




}
