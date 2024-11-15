import QtQuick 6.8
import QtQuick.Controls 2.5
import QtMultimedia
import QtQuick.Effects
import QtQuick.Layouts

Page {
    id: signUp

    Video {
        id: video
        height: parent.height
        source: themeManager.currentTheme.sign_up_props.bg_source

        anchors.horizontalCenter: parent.horizontalCenter
        autoPlay: true
        loops: MediaPlayer.Infinite

        z: -1

        onSourceChanged: {
            console.log("source: " + source);
            console.log("Buffer Size [" + bufferProgress + "]");
            video.play();
        }

        onPlaying: {
            console.log("Buffer Size [" + bufferProgress + "]");
        }
    }

    Rectangle {
        id: preloading
        anchors.fill: parent
        color: "black"
        opacity: video.playing ? 0 : 1
        z: 3
        Behavior on opacity {
            NumberAnimation {
                duration: 10
            }
        }
    }

    TextField {
        id: xux

        maximumLength: 20
        width: 300 * themeManager.currentTheme.app_ui_scale_factor
        height: 30 * themeManager.currentTheme.app_ui_scale_factor

        color: "cyan"
        placeholderText: "uxu"
        placeholderTextColor: "white"

        font.pixelSize: 18 * themeManager.currentTheme.app_ui_scale_factor

        leftPadding: 10 * themeManager.currentTheme.app_ui_scale_factor

        anchors.centerIn: parent

        Keys.onEscapePressed: {
            if (xux.focus)
                xux.focus = false;
        }

        background: Rectangle {
            anchors.fill: parent
            radius: 4 * themeManager.currentTheme.app_ui_scale_factor
            color: "#272727"

            MouseArea {
                anchors.fill: parent

                hoverEnabled: true
            }
        }
    }

    Button {
        text: "change bg"

        onClicked: {
            themeManager.update(themeManager.currentTheme.app_props.theme_name == "zurui_light" ? "zurui_dark" : "zurui_light");
            // console.log(themeManager.currentTheme.sign_up_props.bg_source);
            // console.log(themeManager.currentTheme.app_props.theme_name);
        }
    }

    Button {
        text: "Back"
        anchors.horizontalCenter: parent
        onClicked: {
            stackView.replaceCurrentItem(signInLoader.item);
            console.log(stackView.depth);
        }
    }

    MultiEffect {
        id: blur
        source: video
        anchors.fill: video
        brightness: 0
        saturation: 0.1
        blurEnabled: true
        blurMax: 64
        blur: 0

        z: -1

        Behavior on blur {
            NumberAnimation {
                duration: 320
                easing.type: Easing.OutQuart
            }
        }

        Behavior on brightness {
            NumberAnimation {
                duration: 320
                easing.type: Easing.OutQuart
            }
        }
    }

    Connections {
        target: themeManager

        function onCurrentThemeChanged() {
            if (zurui_debug)
                console.log("Themes have changed, currentTheme:", themeManager.currentTheme);
            video.source = themeManager.currentTheme.sign_up_props.bg_source;
        }
    }

    Connections {
        target: keyBindingManager

        function onToggleBlur() {
            blur.blur = blur.blur == 0 ? 0.55 : 0;
            blur.brightness = blur.brightness == 0 ? -.15 : 0;
        }
    }
}
