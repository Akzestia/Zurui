cmake_minimum_required(VERSION 3.31)

qt_add_library(key_binding_manager STATIC)

qt_add_qml_module(key_binding_manager
    URI "KeyBindingManager"
    VERSION 1.0
    SOURCES
        key_binding_manager.cpp key_binding_manager.h
        key_binding_worker.cpp key_binding_worker.h
    RESOURCE_PREFIX /key_binding_manager
)

target_link_libraries(key_binding_manager
    PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Gui
        Qt6::Qml
        stdc++
)
