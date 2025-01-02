import QtQuick 6.8
import QtQuick.Controls 2.5
import QtMultimedia
import QtQuick.Effects
import QtQuick.Layouts
import UIcomponents 1.0

Item {
    id: signIn

    Rectangle {
        id: content_wrapper

        implicitWidth: 480 * themeManager.currentTheme.app_ui_scale_factor * .95
        implicitHeight: 640 * themeManager.currentTheme.app_ui_scale_factor * .95

        anchors.centerIn: parent

        color: themeManager.currentTheme.auth_window_props.sign_in_bg_color
        radius: themeManager.currentTheme.auth_window_props.sign_in_frame_radius * themeManager.currentTheme.app_ui_scale_factor

        ColumnLayout {
            id: c_layout
            width: parent.width * .92
            height: parent.height * .6
            anchors {
                centerIn: parent
            }

            CTextInput {
                id: user_name_input
                Layout.preferredWidth: content_wrapper.implicitWidth * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Username")
                can_change: auth_btn.is_processing
                Layout.alignment: Qt.AlignCenter
            }

            CTextInput {
                id: password_input
                Layout.preferredWidth: content_wrapper.width * .75
                Layout.preferredHeight: 35
                isPasswordField: true
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Password")
                can_change: auth_btn.is_processing
                Layout.alignment: Qt.AlignCenter
            }

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Text {
                    text: qsTr("Don't have an account?")
                    color: themeManager.currentTheme.auth_window_props.sign_in_switch_label_text_color
                }
                Text {
                    id: sign_up_label

                    text: qsTr("Sign Up")
                    font.underline: true
                    Layout.leftMargin: 1.5

                    color: themeManager.currentTheme.auth_window_props.sign_in_switch_label_text_color

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onEntered: {
                            sign_up_label.color = themeManager.currentTheme.auth_window_props.sign_in_switch_label_hover_text_color;
                            console.log("entered" + sign_up_label.color);
                        }
                        onExited: {
                            sign_up_label.color = themeManager.currentTheme.auth_window_props.sign_in_switch_label_text_color;
                            console.log("exited" + sign_up_label.color);
                        }

                        onClicked: {
                            if (auth_btn.is_processing)
                                return;
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

            AuthButton {
                id: auth_btn
                Layout.preferredWidth: content_wrapper.width * .56
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignCenter

                is_sign_up: false
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
