cmake_minimum_required(VERSION 3.16)
set(CMAKE_AUTORCC ON)

# Define translation files
set(TS_FILES
    translations/translations_en.ts
    translations/translations_ja.ts
    translations/translations_ua.ts
)

# Define output QM files
set(QM_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/translations")
set(QM_FILES
    "${QM_OUTPUT_DIR}/translations_en.qm"
    "${QM_OUTPUT_DIR}/translations_ja.qm"
    "${QM_OUTPUT_DIR}/translations_ua.qm"
)

# Create the translation_tools library
qt_add_library(translation_tools STATIC)

# Create a separate target for translations
add_custom_target(translations_target
    # Create output directory
    COMMAND ${CMAKE_COMMAND} -E make_directory ${QM_OUTPUT_DIR}
    # Update translations
    COMMAND lupdate ${CMAKE_CURRENT_SOURCE_DIR}/../ -ts ${TS_FILES}
    # Generate QM files with specific output paths
    COMMAND lrelease translations/translations_en.ts -qm ${QM_OUTPUT_DIR}/translations_en.qm
    COMMAND lrelease translations/translations_ja.ts -qm ${QM_OUTPUT_DIR}/translations_ja.qm
    COMMAND lrelease translations/translations_ua.ts -qm ${QM_OUTPUT_DIR}/translations_ua.qm
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating translations"
    VERBATIM
)

# Create a resource file for the translations
set(QRC_FILE "${CMAKE_CURRENT_BINARY_DIR}/translations.qrc")
file(WRITE ${QRC_FILE} "<!DOCTYPE RCC>\n<RCC version=\"1.0\">\n    <qresource prefix=\"/translation_tools/translations\">\n")
foreach(QM_FILE ${QM_FILES})
    get_filename_component(QM_BASENAME ${QM_FILE} NAME)
    file(APPEND ${QRC_FILE} "        <file alias=\"${QM_BASENAME}\">${QM_FILE}</file>\n")
endforeach()
file(APPEND ${QRC_FILE} "    </qresource>\n</RCC>")

# Add custom command to ensure QRC file is regenerated when needed
add_custom_command(
    OUTPUT ${QRC_FILE}
    DEPENDS ${QM_FILES}
    COMMAND ${CMAKE_COMMAND} -E touch ${QRC_FILE}
    COMMENT "Updating translations QRC file"
)

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

# Set up proper dependencies
add_dependencies(translation_tools translations_target)

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
