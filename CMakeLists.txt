cmake_minimum_required(VERSION 3.31)

project(Zurui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

find_package(Qt6 6.8.1 REQUIRED COMPONENTS Quick Core Multimedia ShaderTools LinguistTools Widgets)

qt_standard_project_setup(REQUIRES 6.8.1)

qt_add_executable(xZurui
    main.cpp
)

qt_add_qml_module(xZurui
    URI Zurui
    VERSION 1.0
    QML_FILES
        Main.qml
)

target_link_libraries(xZurui
    PRIVATE
        Qt6::Quick
        Qt6::Widgets
        Qt6::Multimedia
        Qt6::Gui
        Qt6::Qml
)

include(GNUInstallDirs)
install(TARGETS xZurui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
