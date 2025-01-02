import QtQuick 6.8

Item {
    id: auth_btn
    property bool is_sign_up: true
    property bool disabled: false
    property bool is_processing: false

    Rectangle {
        id: btn

        anchors.centerIn: parent

        width: parent.width
        height: parent.height

        radius: themeManager.currentTheme.auth_window_props.auth_btn_radius * themeManager.currentTheme.app_ui_scale_factor
        color: themeManager.currentTheme.auth_window_props.auth_btn_color

        Behavior on color {
            ColorAnimation {
                duration: auth_btn.disabled ? 0 : 350
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on width {
            NumberAnimation {
                duration: 400
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on radius {
            NumberAnimation {
                duration: 400
                easing.type: Easing.InOutQuad
            }
        }

        Text {
            id: btn_text
            anchors.centerIn: parent

            text: auth_btn.is_sign_up ? themeManager.currentTheme.auth_window_props.auth_btn_sign_up_text : themeManager.currentTheme.auth_window_props.auth_btn_sign_in_text
            color: themeManager.currentTheme.auth_window_props.auth_btn_text_color

            Behavior on color {
                ColorAnimation {
                    duration: auth_btn.disabled ? 0 : 350
                    easing.type: Easing.InOutQuad
                }
            }
        }

        MouseArea {
            id: mouse_area
            anchors.fill: parent
            hoverEnabled: true
            acceptedButtons: Qt.AllButtons

            onEntered: {
                if (auth_btn.is_processing)
                    return;
                btn_text.color = themeManager.currentTheme.auth_window_props.auth_btn_text_hover_color;
                btn.color = themeManager.currentTheme.auth_window_props.auth_btn_hover_color;
            }

            onReleased: {
                console.log("released");
                auth_btn.is_processing = true;
                auth_btn.disabled = true;
                btn_text.visible = false;
                btn.width = auth_btn.height;
            }

            onPressedChanged: {
                if (auth_btn.is_processing)
                    return;
                console.log("Pressed: " + containsPress);
                console.log("Disabled: " + auth_btn.disabled);
                if (containsPress) {
                    auth_btn.disabled = true;
                    btn_text.color = themeManager.currentTheme.auth_window_props.auth_btn_clicked_text_color;
                    btn.color = themeManager.currentTheme.auth_window_props.auth_btn_clicked_color;
                    return;
                }
                console.log("unpressed");

                auth_btn.disabled = false;
                btn_text.color = themeManager.currentTheme.auth_window_props.auth_btn_text_hover_color;
                btn.color = themeManager.currentTheme.auth_window_props.auth_btn_hover_color;
            }

            onExited: {
                if (auth_btn.is_processing)
                    return;
                btn_text.color = themeManager.currentTheme.auth_window_props.auth_btn_text_color;
                btn.color = themeManager.currentTheme.auth_window_props.auth_btn_color;
            }
        }
    }
}
