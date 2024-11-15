import QtQuick
import QtQuick.Controls
import UIcomponents

Window {
    id: mainWindow

    maximumWidth: 480 * themeManager.currentTheme.app_ui_scale_factor
    maximumHeight: 640 * themeManager.currentTheme.app_ui_scale_factor
    minimumWidth: 480 * themeManager.currentTheme.app_ui_scale_factor
    minimumHeight: 640 * themeManager.currentTheme.app_ui_scale_factor
    visible: true
    title: qsTr("Zurui")

    /*
        The `mode` property is used to indicate the currently rendered component:

            Mode 0 -> Sign In
            Mode 1 -> Sign Up
    */
    // property int mode: 0

    Component {
        id: signInComponent

        SignIn {}
    }

    Loader {
        id: signInLoader
        sourceComponent: signInComponent
        visible: false  // Initially hidden
    }

    Component {
        id: signUpComponent

        SignUp {}
    }

    Loader {
        id: signUpLoader
        sourceComponent: signUpComponent
        visible: false  // Initially hidden
    }

    // Loader {
    //     sourceComponent: mode === 0 ? signInComponent : signUpComponent
    //     anchors.fill: parent
    // }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: signInComponent

        popEnter: Transition {
            XAnimator {
                from: (stackView.mirrored ? -1 : 1) * -stackView.height
                to: 0
                duration: 10000
                easing.type: Easing.OutCubic
            }
        }

        popExit: Transition {
            XAnimator {
                from: 0
                to: (stackView.mirrored ? -1 : 1) * stackView.height
                duration: 10000
                easing.type: Easing.OutCubic
            }
        }
    }

    onActiveFocusItemChanged: {
        console.log("Active Focus Item:", activeFocusItem);
        console.log("Class Name:", activeFocusItem.objectName);
        console.log("Item ID:", activeFocusItem.data);
        console.log("Parent:", activeFocusItem.parent);

        if (activeFocusItem) {
            keyBindingManager.setFocusedItem(activeFocusItem);
        }
    }
}
