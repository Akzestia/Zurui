import QtQuick
import QtQuick.Effects
import QtQuick.Controls
import UIcomponents
import QtMultimedia

Window {
    id: mainWindow

    Item {
        id: rootMask
        anchors.fill: parent
    }

    Connections {
        target: themeManager
        function onCurrentThemeChanged() {
        //called when any of theme files was updated
        }
    }

    visibility: Windowed

    // maximumWidth: 480 * themeManager.currentTheme.app_ui_scale_factor
    // maximumHeight: 640 * themeManager.currentTheme.app_ui_scale_factor
    minimumWidth: 480 * themeManager.currentTheme.app_ui_scale_factor
    minimumHeight: 640 * themeManager.currentTheme.app_ui_scale_factor

    visible: true
    title: qsTr("Zurui")

    Component {
        id: signInComponentL

        SignIn {}
    }

    Loader {
        id: signInLoader
        sourceComponent: signInComponentL
        opacity: 1

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: parent.left
        }

        Behavior on anchors.leftMargin {
            PropertyAnimation {
                duration: themeManager.currentTheme.animation_props.surface_switch_duration
                easing.type: Easing.InOutQuad

                onFinished: {
                    signInLoader.anchors.rightMargin = 0;
                }
            }
        }

        Behavior on opacity {
            NumberAnimation {
                duration: themeManager.currentTheme.animation_props.surface_opacity_duration
                easing.type: Easing.InOutQuad
            }
        }

        Component.onCompleted: {
            if (opacity == 0)
                signInLoader.anchors.leftMargin = Screen.width * -1;
        }
    }

    Component {
        id: signUpComponentL

        SignUp {}
    }

    Loader {
        id: signUpLoader
        sourceComponent: signUpComponentL
        opacity: 0

        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: parent.left
        }

        Behavior on anchors.leftMargin {
            PropertyAnimation {
                duration: themeManager.currentTheme.animation_props.surface_switch_duration
                easing.type: Easing.InOutQuad
            }
        }

        Behavior on opacity {
            NumberAnimation {
                duration: themeManager.currentTheme.animation_props.surface_opacity_duration
                easing.type: Easing.InOutQuad
            }
        }

        Component.onCompleted: {
            if (opacity == 0)
                signUpLoader.anchors.leftMargin = Screen.width;
        }
    }

    onActiveFocusItemChanged: {
        if (activeFocusItem) {
            keyBindingManager.setFocusedItem(activeFocusItem);
        }
    }

    Loader {
        id: auth_window_bg
        sourceComponent: themeManager.currentTheme.auth_window_props.bg_animated ? animated_bg : static_bg

        z: -1
        height: parent.height
        clip: true
        anchors.centerIn: parent
    }

    Connections {
        target: auth_window_bg.item

        function onWidthChanged() {
            console.log(auth_window_bg.item.width);
        }

        function onHeightChanged() {
            console.log("Height of item");
            console.log(auth_window_bg.item.height);
        }
    }

    Component {
        id: animated_bg

        Video {
            id: app_bg_video
            source: themeManager.currentTheme.auth_window_props.animated_bg_source

            anchors.horizontalCenter: parent.horizontalCenter
            autoPlay: true
            loops: MediaPlayer.Infinite
            scale: 1.3
            z: -1

            layer.enabled: true

            onSourceChanged: {
                app_bg_video.play();
            }
        }
    }

    Component {
        id: static_bg

        Image {
            id: app_bg_static
            height: Screen.height
            source: themeManager.currentTheme.auth_window_props.static_bg_source

            anchors.horizontalCenter: parent.horizontalCenter
            z: -1
        }
    }

    Connections {
        target: keyBindingManager

        function onToggleBlur() {
            console.log("Blur");
            console.log("Source item width: [" + auth_window_bg.item.width + "]");
        }
    }

    onWidthChanged: {
        if (signInLoader.opacity == 0 && signInLoader.anchors.leftMargin != mainWindow.width * -1)
            signInLoader.anchors.leftMargin = mainWindow.width * -1;
    }
}
