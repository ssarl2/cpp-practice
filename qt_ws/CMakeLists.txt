cmake_minimum_required(VERSION 3.10)

project(qt_beginner)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# set(CMAKE_BUILD_TYPE Debug) # non-optimized code with debug symbols
set(CMAKE_BUILD_TYPE RelWithDebInfo) # optimized code with debug symbols

include_directories(include)
include_directories(interface)

find_package(Qt5 REQUIRED
    Core
    Gui
    Widgets
    PrintSupport
)
find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})

set(SOURCES
    src/main.cpp
    src/Home.cpp
    src/MenuBarBase.cpp
    src/window.cpp
    src/ui_size.cpp
    src/email.cpp
    include/window.h ## In order to be able to recognize Q_OBJECT by automoc(meta-object compiler), header should be added
    interface/IMenuBarFactorySubscriber.h ## In order to be able to recognize Q_OBJECT by automoc(meta-object compiler), header should be added
)

set(LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::PrintSupport
    ${CURL_LIBRARIES}
)

add_executable(qt ${SOURCES})
target_link_libraries(qt ${LIBS})