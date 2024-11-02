cmake_minimum_required(VERSION 3.16)
set(CMAKE_AUTORCC ON)

qt_add_library(zurui_light STATIC)

qt_add_qml_module(zurui_light
    URI "Zurui_light"
    VERSION 1.0
    QML_FILES
        conf.qml
    RESOURCE_PREFIX
        /zurui_light
)

qt_add_resources(zurui_light "assets"
    PREFIX
        /zurui_light
    FILES
        assets/tendou-alice-blue-archive-moewalls-com.mp4
)

target_link_libraries(zurui_light
    PRIVATE
        Qt6::Core
        Qt6::Quick
)
