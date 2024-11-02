cmake_minimum_required(VERSION 3.16)
set(CMAKE_AUTORCC ON)

qt_add_library(zurui_dark STATIC)

qt_add_qml_module(zurui_dark
    URI "Zurui_dark"
    VERSION 1.0
    QML_FILES
        conf.qml
    RESOURCE_PREFIX
        /zurui_dark
)

qt_add_resources(zurui_dark "assets"
    PREFIX
        /zurui_dark
    FILES
        assets/plana-blue-archive-moewalls-com.mp4
)

target_link_libraries(zurui_dark
    PRIVATE
        Qt6::Core
        Qt6::Quick
)
