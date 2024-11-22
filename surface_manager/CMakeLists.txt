cmake_minimum_required(VERSION 3.31)

qt_add_library(surface_manager STATIC)

qt_add_qml_module(surface_manager
    URI "SurfaceManager"
    VERSION 1.0
    SOURCES
        surface_manager.cpp surface_manager.h
        surface.cpp surface.h
        surface_worker.cpp surface_worker.h
    RESOURCE_PREFIX /surface_manager
)

target_link_libraries(surface_manager
    PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Gui
        Qt6::Qml
        Qt6::Multimedia
        stdc++
)
