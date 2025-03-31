pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Layouts
import QtMultimedia

Window {
    id: main_window
    title: qsTr("ずるい")

    visible: true
    visibility: Window.Windowed
    flags: Qt.FramelessWindowHint

    minimumWidth: 1020
    maximumWidth: 1020
    minimumHeight: 580
    maximumHeight: 580

    color: "#212121"

    Video {
        anchors.fill: parent
        source: "http://localhost:3000/assets/arkria.mp4"
        autoPlay: true
        loops: MediaPlayer.Infinite
        scale: 1.3

        layer.enabled: true

        onErrorChanged: console.log("Error:", errorString)
        onPlaybackStateChanged: console.log("State:", playbackState)
        Component.onCompleted: console.log("Video source:", source)
    }

    // Loader {
    //     // Used for representing the current application canvas (Auth | Main)
    //     // Auth canvas includes SignUp & SignIn
    //     // Main canvas includes MainScreen, Settings etc.
    //     id: root_loader

    //     source: ""
    // }

    // // Keep in mind, that using Loaders for caching qml elements will increase RAM usage.
    // // For example, keeping the state of the element with a video of size N will consume N size of RAM.
    // // For those who has 32 or even mroe GB of RAM enjoy completely wait free page loading experience ^_^!

    // Loader {
    //     // Can be used to store previously rendered qml elements.
    //     // For example when user goes from the main screen to the settings etc,
    //     // U can store the main screen in past_loader instance
    //     id: past_loader

    //     enabled: false
    // }

    // Loader {
    //     // Can be used for preloading of the next possible qml.
    //     // For example when user hovers over some menu item
    //     // future_loader can be used to preload the corresponding qml element.
    //     id: future_loader

    //     enabled: false
    // }
}
