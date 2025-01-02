import QtQuick 6.8
import QtQuick.Controls 2.5
import QtQuick.Layouts
import UIcomponents
import QtQuick.Effects

Item {
    id: signUp

    Rectangle {
        id: content_wrapper

        implicitWidth: 480 * themeManager.currentTheme.app_ui_scale_factor * .95
        implicitHeight: 640 * themeManager.currentTheme.app_ui_scale_factor * .95

        anchors.centerIn: parent

        color: themeManager.currentTheme.auth_window_props.sign_up_bg_color
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
                Layout.preferredWidth: content_wrapper.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Username")
                can_change: auth_btn.is_processing
                Layout.alignment: Qt.AlignHCenter
            }
            CTextInput {
                id: user_email_input
                Layout.preferredWidth: content_wrapper.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Email")
                can_change: auth_btn.is_processing
                Layout.alignment: Qt.AlignHCenter
            }
            CTextInput {
                id: password_input
                Layout.preferredWidth: content_wrapper.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Password")
                can_change: auth_btn.is_processing
                Layout.alignment: Qt.AlignHCenter
            }
            CTextInput {
                id: repeat_password_input
                Layout.preferredWidth: content_wrapper.width * .75
                Layout.preferredHeight: 35
                cwidth: user_name_input.Layout.preferredWidth
                cheight: user_name_input.Layout.preferredHeight
                placeholderText: qsTr("Repeat password")
                can_change: auth_btn.is_processing
                Layout.alignment: Qt.AlignHCenter
            }

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Text {
                    text: qsTr("Already have an account?")
                    color: themeManager.currentTheme.auth_window_props.sign_in_switch_label_text_color
                }
                Text {
                    id: sign_in_label

                    text: qsTr("Sign In")
                    font.underline: true
                    Layout.leftMargin: 1.5

                    color: themeManager.currentTheme.auth_window_props.sign_in_switch_label_text_color

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        onEntered: {
                            sign_in_label.color = themeManager.currentTheme.auth_window_props.sign_in_switch_label_hover_text_color;
                            console.log("entered" + sign_in_label.color);
                        }
                        onExited: {
                            sign_in_label.color = themeManager.currentTheme.auth_window_props.sign_in_switch_label_text_color;
                            console.log("exited" + sign_in_label.color);
                        }

                        onClicked: {
                            if (auth_btn.is_processing)
                                return;
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

            AuthButton {
                id: auth_btn
                Layout.preferredWidth: content_wrapper.width * .56
                Layout.preferredHeight: 40
                Layout.alignment: Qt.AlignCenter
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
