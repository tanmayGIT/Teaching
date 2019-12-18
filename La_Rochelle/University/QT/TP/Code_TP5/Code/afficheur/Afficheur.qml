 import QtQuick 1.0
 
Rectangle {
		id: afficheur
		
		property bool isSelected: false
		property int defaultWidth: 100
		property int defaultHeight: 100
		property int bigWidth: 200
		property int bigHeight: 200
		
		width: defaultWidth; height: defaultHeight
		color: "white"
		border.width: 5
		
		border.color: (isSelected == false) ? "black" : "red"
				
		 MouseArea {
			anchors.fill: parent
		    // hoverEnabled: true sinon onEntered declenche seulement sur clic
			hoverEnabled: true
			onEntered: afficheur.state = 'agrandissement';
			acceptedButtons: Qt.LeftButton | Qt.RightButton
			onClicked: { 
				if( mouse.button == Qt.RightButton)
					afficheur.state = '';
				else
					afficheur.state = 'selection';
			}
			// Etat par defaut
			//onExited: afficheur.state = '';
			onExited: afficheur.state = 'horsFocus';
		}
				
		states: [
			State {
				name: "selection"
				PropertyChanges { 
					target: afficheur
					//border.color: "red"
					isSelected: true
					width: afficheur.width
					height: afficheur.height
				}
			},			
			State {
				name: "agrandissement"
				PropertyChanges { 
					target: afficheur
					width: bigWidth
					height: bigHeight
					isSelected: afficheur.isSelected
				}
			},
			State {
				name: "horsFocus"
				PropertyChanges { 
					target: afficheur
					width: defaultWidth
					height: defaultHeight
					isSelected: afficheur.isSelected
				}
			}
			
	    ]
		
		 transitions: [
			Transition {
				NumberAnimation { properties: "width,height"; duration: 500 }
			}
		]
		
	}