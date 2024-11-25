cmake_minimum_required(VERSION 3.31)

qt_add_library(systray STATIC)

qt_add_qml_module(systray
    URI "SystemTray"
    VERSION 1.0
    SOURCES
        systray.cpp systray.h
    RESOURCE_PREFIX /systray
)

target_link_libraries(systray
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Quick
        Qt6::Gui
        Qt6::Qml
        stdc++
)
