qt_add_library(ui_components STATIC)

qt_add_qml_module(ui_components
    URI "UIcomponents"
    VERSION 1.0
    QML_FILES
        Sign_in.qml
        Sign_up.qml
    RESOURCE_PREFIX /ui_components
)
