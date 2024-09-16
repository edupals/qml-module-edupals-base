
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 "6.7.0" REQUIRED COMPONENTS Qml Quick)

find_package(EdupalsBase REQUIRED)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fexceptions")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -foperator-names")

add_library(edupalsbaseplugin SHARED plugin.cpp)

target_link_libraries (edupalsbaseplugin
    Qt6::Qml
    Qt6::Quick
    Edupals::Base
)

install (TARGETS edupalsbaseplugin DESTINATION ${QT6_INSTALL_QML}/Edupals/Base)
install(FILES qmldir DESTINATION ${QT6_INSTALL_QML}/Edupals/Base)
