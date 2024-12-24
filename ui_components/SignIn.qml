import QtQuick 6.8
import QtQuick.Controls 2.5
import QtMultimedia
import QtQuick.Effects
import QtQuick.Layouts
import UIcomponents 1.0

Item {
    id: signIn

    Rectangle {
        id: blur_bg

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
                id: password_input
                Layout.preferredWidth: c_layout.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Password")
                Layout.alignment: Qt.AlignHCenter
            }

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Text {
                    text: qsTr("Don't have an account?")
                }
                Text {
                    id: sign_up_label

                    text: qsTr("Sign Up")
                    font.underline: true
                    Layout.leftMargin: 1.5

                    color: "#000000"

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onEntered: {
                            sign_up_label.color = "cyan";
                            console.log("entered" + sign_up_label.color);
                        }
                        onExited: {
                            sign_up_label.color = "black";
                            console.log("exited" + sign_up_label.color);
                        }

                        onClicked: {
                            signInLoader.anchors.leftMargin = mainWindow.width * -1;
                            signInLoader.opacity = 0;
                            signUpLoader.opacity = 1;
                            signUpLoader.anchors.leftMargin = mainWindow.width;
                            signUpLoader.anchors.leftMargin = 0;
                        }
                    }

                    Behavior on color {
                        ColorAnimation {
                            duration: 150
                        }
                    }
                }
            }

            Button {
                text: "Go to Main"
                onClicked: {
                    if (signInLoader.opacity != 0)
                        signInLoader.opacity = 0;
                    if (signUpLoader.opacity != 0)
                        signUpLoader.opacity = 0;
                }
            }
        }
    }

    Connections {
        target: themeManager

        function onCurrentThemeChanged() {
            if (zurui_debug)
                console.log("Themes have changed, currentTheme:", themeManager.currentTheme);
        }
    }
}
