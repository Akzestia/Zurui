cmake_minimum_required(VERSION 3.31)

qt_add_library(preloading_manager STATIC)

qt_add_qml_module(preloading_manager
    URI "PreloadingManager"
    VERSION 1.0
    SOURCES
        preloading_manager.cpp preloading_manager.h
        preloading_worker.cpp preloading_worker.h
    RESOURCE_PREFIX /preloading_manager
)

target_link_libraries(preloading_manager
    PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Gui
        Qt6::Qml
        stdc++
)
