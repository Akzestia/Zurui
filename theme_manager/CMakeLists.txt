qt_add_library(theme_manager STATIC)

qt_add_qml_module(theme_manager
    URI "ThemeManager"
    VERSION 1.0
    SOURCES
        theme_manager.cpp theme_manager.h
    RESOURCE_PREFIX /theme_manager
)
