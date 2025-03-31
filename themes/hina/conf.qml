pragma Singleton
import QtQuick

QtObject {
    property var authentication_window: QtObject {
        property string bg_color: ""
        property real border_radius: 10

        property string font_color: ""
        property string font_family: ""
        property real font_size: 15
    }
}
