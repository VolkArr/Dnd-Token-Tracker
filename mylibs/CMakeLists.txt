cmake_minimum_required(VERSION 3.14)

project(mylibs LANGUAGES CXX)

include_directories(.)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets REQUIRED)







add_library(${PROJECT_NAME}
  ./character.cpp
  ./player.cpp
  ./person.cpp
  ./characterstatmenu.cpp
  ./playerstatmenu.cpp
  ./list.cpp
  ./menu.cpp
  ./editablelabel.cpp
  ./tab.cpp
  ./playerinitiativewindow.cpp
  ./character.h
  ./player.h
  ./person.h
  ./characterstatmenu.h
  ./playerstatmenu.h
  ./list.h
  ./menu.h
  ./editablelabel.h
  ./playerinitiativewindow.h
  ./tab.h
)

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets utils)
