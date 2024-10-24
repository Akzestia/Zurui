cmake_minimum_required(VERSION 3.16)

project(Zurui VERSION 0.1 LANGUAGES CXX)
add_compile_definitions(ZURUI_DEBUG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appZurui
    main.cpp
)

qt_add_qml_module(appZurui
    URI Zurui
    VERSION 1.0
    QML_FILES
        Main.qml
)

add_subdirectory(ui_components)
add_subdirectory(translation_tools)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appZurui PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appZurui
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appZurui
    PRIVATE
        Qt6::Quick
        ui_componentsplugin
        translation_toolsplugin
)

include(GNUInstallDirs)
install(TARGETS appZurui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(SOURCE_THEMES ${CMAKE_SOURCE_DIR}/ui_themes)
set(DESTINATION_THEMES ${CMAKE_BINARY_DIR}/ui_themes)

add_custom_command(
    TARGET appZurui POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DESTINATION_THEMES}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_THEMES} ${DESTINATION_THEMES}
    COMMENT "Copying theme files from ${SOURCE_THEMES} to ${DESTINATION_THEMES}"
)
