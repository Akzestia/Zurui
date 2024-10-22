import QtQuick
import UIComponents 1.0

Window {

    id: mainWindow

    maximumWidth: 480
    maximumHeight: 640
    minimumWidth: 480
    minimumHeight: 640
    visible: true
    title: qsTr("Zurui")

    /*
        The `mode` property is used to indicate the currently rendered component:

            Mode 0 -> Sign In
            Mode 1 -> Sign Up
    */
    property int mode: 0

    Component {
        id: signInComponent

        SignIn {

        }
    }

    Component {
        id: signUpComponent

        SignUp {

        }
    }

    Loader {
        sourceComponent: mode === 0 ? signInComponent : signUpComponent
        anchors.fill: parent
    }
}
