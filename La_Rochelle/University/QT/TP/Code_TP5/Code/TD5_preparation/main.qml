import QtQuick 2.3
import QtQuick.Controls 1.2

import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 500
    height: 550
    title: qsTr("TP5")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: txt1.text = "Open clicked";
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

//    Text {
//        id : txt1
//        text: qsTr("Hello World")
//        anchors.centerIn: parent
//    }

    Rectangle{
        id : rect1
        width: 200
        height: 300
        anchors.leftMargin: 10

        Image{
            id:img1
            anchors.fill: parent
            source:"img/img1.jpg"
        }
        Text {
            id: txtRect2
            text: qsTr("Image 1")
            color: "#FFFFFF"
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }
        MouseArea{
            anchors.fill : parent
            onEntered: {parent.opacity=0.5}
            onExited: {parent.opacity=1}
        }
        Button{
            id:btn1
            text:"Changer"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
//            anchors.top:flickImg2.bottom
            onClicked: fileSelect1.open()   // cropAction
        }
    }



    Rectangle{
        id : rect2
        width: 200
        height: 300
        anchors.left: rect1.right
        anchors.leftMargin: 10

        Image{
            id:img2
            anchors.fill: parent
            source:"img/img2.jpg"
        }
    }

    //import QtQuick.Dialogs 1.2
    FileDialog{
        id:fileSelect1
        title:"Please choose a file"
//        nameFilters:
        selectExisting: true
        selectMultiple: false
        selectFolder: false

        onAccepted: {
            img1.source = fileUrl
        }

    }


    Flickable{
        id:flickImg2
//        anchors.left:rect2.left
        anchors.top:rect1.bottom
        anchors.topMargin: 10
        width:410
        height: 200

        contentWidth: img3.width*2
        contentHeight: img3.height*2
        clip:true


        Image{
            id:img3
            source:"img/img1.jpg"
            width: parent.width*2
            height: parent.height*2
        }

    }


}
