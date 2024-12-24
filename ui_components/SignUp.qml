import QtQuick 6.8
import QtQuick.Controls 2.5
import QtQuick.Layouts
import UIcomponents
import QtQuick.Effects

Item {
    id: signUp

    Panel {
        id: panel1
        implicitWidth: 480 * themeManager.currentTheme.app_ui_scale_factor * .95
        implicitHeight: 640 * themeManager.currentTheme.app_ui_scale_factor * .95

        anchors.centerIn: parent
        clip: true
    }

    Item {
        id: maskItem
        anchors.fill: parent
        layer.enabled: true
        layer.smooth: true
        visible: false

        PanelMask {
            item: panel1
        }
    }

    Rectangle {
        id: blur_bg

        // width: signUp.width * .95
        // height: signUp.height * .95

        implicitWidth: 480 * themeManager.currentTheme.app_ui_scale_factor * .95
        implicitHeight: 640 * themeManager.currentTheme.app_ui_scale_factor * .95

        anchors.centerIn: parent

        color: "#ffffff"
        radius: 10 * themeManager.currentTheme.app_ui_scale_factor
        opacity: 1

        ColumnLayout {
            id: c_layout
            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
                bottom: parent.bottom
                topMargin: 100
                bottomMargin: 100
            }

            CTextInput {
                id: user_name_input
                Layout.preferredWidth: c_layout.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Username")
                Layout.alignment: Qt.AlignHCenter
            }
            CTextInput {
                id: user_email_input
                Layout.preferredWidth: c_layout.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Email")
                Layout.alignment: Qt.AlignHCenter
            }
            CTextInput {
                id: password_input
                Layout.preferredWidth: c_layout.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Password")
                Layout.alignment: Qt.AlignHCenter
            }
            CTextInput {
                id: repeat_password_input
                Layout.preferredWidth: c_layout.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Repeat password")
                Layout.alignment: Qt.AlignHCenter
            }

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Text {
                    text: qsTr("Already have an account?")
                }
                Text {
                    id: sign_in_label

                    text: qsTr("Sign In")
                    font.underline: true
                    Layout.leftMargin: 1.5

                    color: "#000000"

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onEntered: {
                            sign_in_label.color = "cyan";
                            console.log("entered" + sign_in_label.color);
                        }
                        onExited: {
                            sign_in_label.color = "black";
                            console.log("exited" + sign_in_label.color);
                        }

                        onClicked: {
                            signUpLoader.anchors.leftMargin = mainWindow.width;
                            signUpLoader.opacity = 0;
                            signInLoader.opacity = 1;
                            signInLoader.anchors.leftMargin = mainWindow.width * -1;
                            signInLoader.anchors.leftMargin = 0;
                        }
                    }

                    Behavior on color {
                        ColorAnimation {
                            duration: 150
                        }
                    }
                }
            }
        }
    }
    component PanelMask: Rectangle {
        required property Item item
        x: item.x
        y: item.y
        width: item.width
        height: item.height
        radius: item.radius
    }

    component Panel: Rectangle {
        id: component
        radius: 20
        color: "transparent"
        border.width: 1
        border.color: "#8090a0"
    }

    // MultiEffect {
    //     anchors.centerIn: parent
    //     source: auth_window_bg.item
    //     autoPaddingEnabled: false
    //     maskEnabled: true
    //     maskSource: maskItem
    //     maskThresholdMin: 0.5
    //     maskSpreadAtMin: 1.0
    //     blurEnabled: true
    //     blurMax: 80
    //     blur: .38
    //     brightness: -.2
    // }

    Connections {
        target: themeManager

        function onCurrentThemeChanged() {
            if (zurui_debug)
                console.log("Themes have changed, currentTheme:", themeManager.currentTheme);
        }
    }
}
