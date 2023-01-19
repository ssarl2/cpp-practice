cmake_minimum_required(VERSION 3.10)

project(qt_beginner)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_package(Qt5 REQUIRED
    Core
    Gui
    Widgets
    PrintSupport
)

set(SOURCES
    src/main.cpp
    src/window.cpp
    src/ui_size.cpp
)

add_executable(qt ${SOURCES})
target_link_libraries(qt Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport)