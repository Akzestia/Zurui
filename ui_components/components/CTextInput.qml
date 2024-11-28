import QtQuick 6.8

Item {
    id: c_text_input

    property real cwidth: 0
    property real cheight: 0

    property string placeholderText: "Enter text"
    property string placeholderColor: "#888888"
    property real placeholderTextSize: 14
    property bool cenabled: false

    property string textColor: "white"
    property real textSize: 14

    property real bgRadius: 3
    property string bgColor: "#343434"

    focus: true

    Rectangle {
        id: bg
        color: c_text_input.bgColor
        radius: c_text_input.bgRadius
        width: c_text_input.cwidth
        height: c_text_input.cheight
        clip: true

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                console.log("TextInput is focused");
                placeholder.y = -c_text_input.cheight * 0.3;
                placeholder.scale = .8;
                placeholder.anchors.leftMargin = 8;
                placeholder_bg.y = -c_text_input.cheight * 0.4;
                placeholder_bg.anchors.leftMargin = 5;
            }

            onExited: {
                console.log("TextInput lost focus");
                if (text_input.text.length === 0 && !text_input.focus) {
                    placeholder.y = (bg.height - placeholder.height) * .25;
                    placeholder.scale = 1;
                    placeholder.anchors.leftMargin = 15;
                    placeholder_bg.y = (bg.height - placeholder.height) * .25;
                    placeholder_bg.anchors.leftMargin = 10;
                }
            }

            onClicked: {
                text_input.focus = true;
            }
        }

        TextInput {
            id: text_input
            height: parent.height * .5
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 15
            anchors.right: parent.right
            anchors.rightMargin: 15
            color: c_text_input.textColor
            font.pixelSize: c_text_input.textSize
            text: ""

            activeFocusOnTab: c_text_input.cenabled

            horizontalAlignment: Text.AlignHCenter

            onFocusChanged: focused => {
                if (focused) {
                    placeholder.y = -c_text_input.cheight * 0.3;
                    placeholder.scale = .8;
                    placeholder.anchors.leftMargin = 8;
                    placeholder_bg.y = -c_text_input.cheight * 0.4;
                    placeholder_bg.anchors.leftMargin = 5;
                } else {
                    console.log("TextInput lost focus");
                    if (text.length === 0 && !text_input.focus) {
                        placeholder.y = (bg.height - placeholder.height) * .25;
                        placeholder.scale = 1;
                        placeholder.anchors.leftMargin = 15;
                        placeholder_bg.y = (bg.height - placeholder.height) * .25;
                        placeholder_bg.anchors.leftMargin = 10;
                    }
                }
                console.log(`Placeholder Y: ${placeholder.y}`);
            }

            Keys.onPressed: event => {
                if (event.key == Qt.Key_Escape) {
                    text_input.focus = false;
                    event.accepted = true;
                }
            }
        }
    }

    Rectangle {
        id: placeholder_bg
        width: placeholder.width * 1.3
        height: placeholder.height * 1.3
        color: c_text_input.bgColor
        radius: c_text_input.bgRadius
        anchors.left: parent.left
        anchors.leftMargin: 10
        y: (bg.height - placeholder.height) * .3

        Behavior on y {
            NumberAnimation {
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on color {
            NumberAnimation {
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on scale {
            NumberAnimation {
                duration: 350
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on anchors.leftMargin {
            NumberAnimation {
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }
    }

    Text {
        id: placeholder
        text: c_text_input.placeholderText
        color: c_text_input.placeholderColor
        font.pixelSize: c_text_input.placeholderTextSize
        height: bg.height * .5
        y: (bg.height - placeholder.height) * .3
        anchors.left: parent.left
        anchors.leftMargin: 20

        Behavior on y {
            NumberAnimation {
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on scale {
            NumberAnimation {
                duration: 350
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on anchors.leftMargin {
            NumberAnimation {
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }
    }

    Component.onCompleted: {
        console.log(cwidth);
        console.log(cheight);
    }
}
