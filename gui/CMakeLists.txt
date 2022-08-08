cmake_minimum_required(VERSION 3.14)

project(DndInitiativeHelper LANGUAGES CXX)


include_directories(.)
include_directories(../utils)
include_directories(../mylibs)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets REQUIRED)


include_directories(.)

add_executable(${PROJECT_NAME} WIN32
  ./main.cpp
  ./mainwindow.cpp
  ./mainwindow.h
)




target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets utils mylibs)
