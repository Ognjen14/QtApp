cmake_minimum_required(VERSION 3.16)

project(QtApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIBRARY_SOURCE squareobject.cpp tcpserverreceive.cpp)
set(LIBRARY_HEADER squareobject.h tcpserverreceive.h)

set(LIBRARY_QML ${CMAKE_CURRENT_SOURCE_DIR}/Main.qml
                ${CMAKE_CURRENT_SOURCE_DIR}/SquareFuild.qml )

set(EXE_SOURCE main.cpp)

set(QT_LIBRARY Qt${QT_VERSION_MAJOR}::Core
               Qt${QT_VERSION_MAJOR}::Network
               Qt${QT_VERSION_MAJOR}::Gui
               Qt${QT_VERSION_MAJOR}::Quick
               Qt${QT_VERSION_MAJOR}::Test)

find_package(QT NAMES  Qt6 CONFIG REQUIRED COMPONENTS Core Network Gui Quick Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Gui Quick Test)
set(CMAKE_AUTOMOC TRUE)
set(CMAKE_AUTORCC TRUE)

add_library(ClientMonitoringLib SHARED ${LIBRARY_HEADER} ${LIBRARY_QML})
target_link_libraries(ClientMonitoringLib ${QT_LIBRARY})

add_executable(ClientMonitoring ${EXE_SOURCE} ${LIBRARY_SOURCE})

target_link_libraries(ClientMonitoring ClientMonitoringLib)

qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(test_ClientMonitoring)
