cmake_minimum_required(VERSION 3.31)

qt_add_library(theme_manager STATIC)

qt_add_qml_module(theme_manager
    URI "ThemeManager"
    VERSION 1.0
    SOURCES
        theme_manager.cpp theme_manager.h
    RESOURCE_PREFIX /theme_manager
)

target_link_libraries(theme_manager
    PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Gui
        Qt6::Qml
        stdc++
)
