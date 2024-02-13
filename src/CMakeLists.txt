
find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Qml Quick)

find_package(EdupalsBase REQUIRED)

include(KDEInstallDirs)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fexceptions")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -foperator-names")

add_library(edupalsbaseplugin SHARED plugin.cpp)

target_link_libraries (edupalsbaseplugin
    Qt5::Qml
    Qt5::Quick
    Edupals::Base
)

install (TARGETS edupalsbaseplugin DESTINATION ${KDE_INSTALL_QMLDIR}/Edupals/Base)
install(FILES qmldir DESTINATION ${KDE_INSTALL_QMLDIR}/Edupals/Base)
