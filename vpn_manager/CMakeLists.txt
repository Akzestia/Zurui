cmake_minimum_required(VERSION 3.16)
qt_add_library(vpn_manager STATIC)

qt_add_qml_module(vpn_manager
    URI "VpnManager"
    VERSION 1.0
    SOURCES
        vpn_manager.cpp vpn_manager.h
    RESOURCE_PREFIX /vpn_manager
)

target_link_libraries(vpn_manager
    PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Gui
        Qt6::Qml
        stdc++
)
