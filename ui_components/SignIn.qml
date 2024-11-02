import QtQuick
import QtQuick.Controls
import QtMultimedia
import Qt5Compat.GraphicalEffects

Item {
    id: signIn

    Video {
        id: video
        height: parent.height
        source: "qrc:/zurui_light/assets/tendou-alice-blue-archive-moewalls-com.mp4"

        anchors.horizontalCenter: parent.horizontalCenter
        autoPlay: true
        loops: MediaPlayer.Infinite
    }

    Rectangle {
        id: mask
        width: .1 * themeManager.currentTheme.app_ui_scale_factor
        height: .1 * themeManager.currentTheme.app_ui_scale_factor

        color: "#FF000000"
        anchors.centerIn: parent

        Component.onCompleted: {
            if (zurui_debug)
                console.log("Scale x" + themeManager.currentTheme.app_ui_scale_factor);
        }
    }

    // TextInput {
    //     id: inputq
    //     text: "Welcome to zurui"
    //     color: "white"
    //     anchors.centerIn: parent
    //     width: 600
    //     focus: false
    //     height: 200
    //     z: 1

    //     Keys.onPressed: event => {
    //         if (event.key == Qt.Key_Escape) {
    //             inputq.focus = false;
    //             event.accepted = true;
    //         }
    //     }
    // }

    Shortcut {
        sequences: ["Ctrl+X"]
        onActivated: {
            mask.width = mask.width === 0 ? 10 : 0;
            mask.height = mask.height === 0 ? 10 : 0;
        }
    }

    MaskedBlur {
        id: blur
        z: 0
        anchors.fill: video
        source: video
        maskSource: mask
        radius: 16
        samples: 24
    }

    Connections {
        target: themeManager

        function onCurrentThemeChanged() {
            if (zurui_debug)
                console.log("Themes have changed, currentTheme:", themeManager.currentTheme);
        }
    }
}
