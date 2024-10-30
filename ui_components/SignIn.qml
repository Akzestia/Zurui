import QtQuick
import QtQuick.Controls

Item {
    id: signIn

    property bool isDebug: Qt.application.property("ZURUI_DEBUG") === true
    property string xuxu: "zurui_dark"

    Rectangle {
        width: parent.width
        height: parent.height

        color: themeManager.currentTheme.app_bg_color

        Behavior on color {
            ColorAnimation {
                duration: 300
            }
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                if (isDebug)
                    console.log(themeManager.availableThemes);
                themeManager.update(xuxu === "zurui_light" ? "zurui_dark" : "zurui_light");
                xuxu = xuxu === "zurui_light" ? "zurui_dark" : "zurui_light";
            }
        }
    }

    Connections {
        target: themeManager

        function onCurrentThemeChanged() {
            if (isDebug)
                console.log("Themes have changed, currentTheme:", themeManager.currentTheme);
        }
    }
}
