qt_add_library(translation_tools STATIC)

set(TS_FILES
    translations/translations_en.ts
    translations/translations_ja.ts
    translations/translations_ua.ts
)

qt_create_translation(QM_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/../
    ${TS_FILES}
)

foreach(QM_FILE ${QM_FILES})
    get_filename_component(QM_BASENAME ${QM_FILE} NAME)
    set_source_files_properties(${QM_FILE} PROPERTIES QT_RESOURCE_ALIAS "translations/${QM_BASENAME}")
endforeach()

qt_add_qml_module(translation_tools
    URI "TranslationTools"
    VERSION 1.0
    SOURCES
        translation_manager.cpp
        translation_manager.h
    RESOURCE_PREFIX /translation_tools
    RESOURCES
        ${QM_FILES}
)

target_include_directories(translation_tools
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/translations
)

target_link_libraries(translation_tools
    PRIVATE
        Qt6::Quick
        Qt6::Gui
)
