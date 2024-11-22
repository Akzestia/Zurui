cmake_minimum_required(VERSION 3.31)

qt_add_library(ui_components STATIC)

qt_add_qml_module(ui_components
    URI "UIcomponents"
    VERSION 1.0
    QML_FILES
        SignIn.qml
        SignUp.qml
    RESOURCE_PREFIX
        /ui_components
)

qt_add_resources(ui_components "materials"
    PREFIX
        /
    FILES
        materials/blur_material.cpp materials/blur_material.h
)
