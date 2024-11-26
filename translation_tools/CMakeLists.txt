cmake_minimum_required(VERSION 3.31)

set(CMAKE_AUTORCC ON)

qt_add_library(translation_tools STATIC)

# Add the QML module
qt_add_qml_module(translation_tools
    URI "TranslationTools"
    VERSION 1.0
    SOURCES
        translation_manager.cpp
        translation_manager.h
    RESOURCE_PREFIX /translation_tools
)

qt_add_resources(appZurui "translations"
    PREFIX
        /
    FILES
        translations/translations_en.qm
        translations/translations_ja.qm
        translations/translations_ua.qm
)

# Include directories and linking
target_include_directories(translation_tools
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/translations
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(translation_tools
    PRIVATE
        Qt6::Quick
        Qt6::Gui
)
