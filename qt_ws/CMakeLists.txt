cmake_minimum_required(VERSION 3.10)

project(qt_beginner)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED
    Core
    Gui
    Widgets
    PrintSupport
)

add_executable(qt src/main.cpp)
target_link_libraries(qt Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport)