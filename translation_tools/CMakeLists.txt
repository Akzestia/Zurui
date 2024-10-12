qt_add_library(translation_tools STATIC)

qt_add_qml_module(translation_tools
    URI "TranslationTools"
    VERSION 1.0
    SOURCES
        translation_manager.cpp translation_manager.h
    RESOURCE_PREFIX /translation_tools
)
