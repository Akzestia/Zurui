cmake_minimum_required(VERSION 3.16)

qt_add_library(ui_components STATIC)

qt_add_qml_module(ui_components
    URI "UIComponents"
    VERSION 1.0
    QML_FILES
        SignIn.qml
        SignUp.qml
    RESOURCE_PREFIX
        "/qt/qml"
)
