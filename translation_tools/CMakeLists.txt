cmake_minimum_required(VERSION 3.31)

set(CMAKE_AUTORCC ON)

# Define translation files
set(TS_FILES
    translations/translations_en.ts
    translations/translations_ja.ts
    translations/translations_ua.ts
)

# Define output QM files
set(QM_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/translations")
set(QM_FILES "")
foreach(TS_FILE ${TS_FILES})
    get_filename_component(BASE_NAME ${TS_FILE} NAME_WE)
    list(APPEND QM_FILES "${QM_OUTPUT_DIR}/${BASE_NAME}.qm")
endforeach()

# Create output directory for translations
file(MAKE_DIRECTORY ${QM_OUTPUT_DIR})

# Custom command for generating .qm files
foreach(TS_FILE ${TS_FILES})
    get_filename_component(BASE_NAME ${TS_FILE} NAME_WE)
    add_custom_command(
        OUTPUT "${QM_OUTPUT_DIR}/${BASE_NAME}.qm"
        COMMAND lrelease ${CMAKE_CURRENT_SOURCE_DIR}/${TS_FILE} -qm ${QM_OUTPUT_DIR}/${BASE_NAME}.qm
        DEPENDS ${TS_FILE}
        COMMENT "Generating ${BASE_NAME}.qm"
    )
endforeach()

# Add a custom target to trigger translation generation
add_custom_target(translations_target ALL DEPENDS ${QM_FILES})

# Create a resource file for translations
set(QRC_FILE "${CMAKE_CURRENT_BINARY_DIR}/translations.qrc")
file(WRITE ${QRC_FILE} "<!DOCTYPE RCC>\n<RCC version=\"1.0\">\n    <qresource prefix=\"/translation_tools/translations\">\n")
foreach(QM_FILE ${QM_FILES})
    get_filename_component(QM_BASENAME ${QM_FILE} NAME)
    file(APPEND ${QRC_FILE} "        <file alias=\"${QM_BASENAME}\">${QM_FILE}</file>\n")
endforeach()
file(APPEND ${QRC_FILE} "    </qresource>\n</RCC>")

# Add custom command to ensure QRC file is updated
add_custom_command(
    OUTPUT ${QRC_FILE}
    DEPENDS ${QM_FILES}
    COMMAND ${CMAKE_COMMAND} -E touch ${QRC_FILE}
    COMMENT "Updating translations QRC file"
)

# Create the translation_tools library
qt_add_library(translation_tools STATIC)

# Add the QML module
qt_add_qml_module(translation_tools
    URI "TranslationTools"
    VERSION 1.0
    SOURCES
        translation_manager.cpp
        translation_manager.h
        ${QRC_FILE}
    RESOURCE_PREFIX /translation_tools
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
