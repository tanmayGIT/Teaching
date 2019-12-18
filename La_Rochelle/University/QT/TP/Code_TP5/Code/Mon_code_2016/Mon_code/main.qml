import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: {
                    messageDialog.show(qsTr("Open action triggered"));
                    //         text1.text = qsTr("bonjour");
                }
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        // Zone1
        Rectangle{
            id: myRect1
            width:200
            height: 300
            border.color: "red"
            anchors.left: parent.left
            anchors.leftMargin: 10

            Image{id: img1
                anchors.fill: parent
                source: "image1.jpg"
            }

            Text
            {id: recctext1
                color: "#FFF"
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 20
                text: "Image 1"

            }

            MouseArea
            {
                id: mArea1
                anchors.fill: parent
                hoverEnabled: true
                //  onEntered: {recctext1.text="souris_in"; recctext2.text="souris_in"}
                //    onExited: recctext1.text="souris_out"
                onEntered: {img1.opacity= 0.5}
                onExited: {img1.opacity= 1.0}

            }

        }

        // Zone2
        Rectangle{
            id: myRect2
            width:200
            height: 300
            color: "transparent"
            border.color: "blue"
            anchors.left: myRect1.right
            anchors.leftMargin: 10

            Image
            {id: img2
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
                source: "image1.jpg"
            }

            Text
            {id: recctext2
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 20
                text: "Image 2"
                color: "#FFF"
            }

            MouseArea
            {
                id: mArea2
                anchors.fill: parent
                hoverEnabled: true
                //  onEntered: {recctext1.text="souris_in"; recctext2.text="souris_in"}
                //    onExited: recctext1.text="souris_out"
                onEntered: {img2.opacity= 0.5}
                onExited: {img2.opacity= 1.0}

            }

            Button{
                id: recbutton2
                text: "Changer"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                onClicked: fileDialog2.open()
            }
        }


        /*        Text {
            id: text1
            x: 249
            y: 98
            width: 180
            height: 87
            text: qsTr("Hello World!")
            font.bold: true
            font.pixelSize:177
        }*/


        Flickable{
            id:flickImg2
        anchors.left:myRect1.left
           anchors.top:myRect1.bottom
            anchors.topMargin: 10
            width:410
            height: 500
            contentWidth: width
            contentHeight: height*3
            clip:true

            boundsBehavior: Flickable.DragOverBounds

            Image{
                id:img3
                source:"image3.png"
                width: parent.width
                height: parent.height
    clip:false
            }


            Image{
                id:img4
                source:"image2.png"
                width: parent.width
                height: parent.height
                anchors.top:img3.bottom
clip:true
            }

        }

    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    FileDialog {
        id: fileDialog2
        onAccepted: img2.source = fileUrl
    }



}
