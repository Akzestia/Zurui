qt_add_library(zurui_client STATIC)

qt_add_qml_module(zurui_client
    URI "ZuruiClient"
    VERSION 1.0
    SOURCES
        zurui_client.cpp zurui_client.h
    RESOURCE_PREFIX /zurui_client
)

target_link_libraries(zurui_client
    PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Gui
        Qt6::Qml
        stdc++
)s
