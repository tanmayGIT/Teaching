 import QtQuick 1.0
 
Rectangle {
     id: container
     width: 500; height: 500
     color: "lightgray"
 
	Row{
		anchors.horizontalCenter: container.horizontalCenter
		anchors.verticalCenter: container.verticalCenter
		Afficheur{ }
	}
 }