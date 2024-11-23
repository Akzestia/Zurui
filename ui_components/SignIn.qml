import QtQuick 6.8
import QtQuick.Controls 2.5
import QtMultimedia
import QtQuick.Effects
import QtQuick.Layouts
import UIcomponents 1.0

Item {
    id: signIn

    ColumnLayout {
        id: c_layout

        anchors.fill: parent

        Rectangle {
            id: blur_bg

            Layout.preferredWidth: signIn.width * .95
            Layout.preferredHeight: signIn.height * .95

            color: "#ffffff"
            radius: 10 * themeManager.currentTheme.app_ui_scale_factor
            opacity: .8

            Layout.alignment: Qt.AlignCenter
        }
    }

    Connections {
        target: themeManager

        function onCurrentThemeChanged() {
            if (zurui_debug)
                console.log("Themes have changed, currentTheme:", themeManager.currentTheme);
            video.source = themeManager.currentTheme.sign_in_props.bg_source;
        }
    }
}
