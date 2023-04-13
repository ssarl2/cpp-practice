cmake_minimum_required(VERSION 3.10)

project(qt_beginner)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_BUILD_TYPE Debug) # non-optimized code with debug symbols
# set(CMAKE_BUILD_TYPE RelWithDebInfo) # optimized code with debug symbols

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
    src/SubMain.cpp
    src/MenuBarBase.cpp
    src/MenuBarPublisher.cpp
    src/Home.cpp
    src/ProgressBar.cpp
    src/Layout.cpp
    # src/window.cpp
)

set(HEADERS_FOR_QOBJECT
    ## In order to be able to recognize Q_OBJECT 
    ## by automoc(meta-object compiler), 
    ## header should be added
    include/Home.h 
    include/ProgressBar.h
    include/Layout.h
    include/SubMain.h
    # include/window.h
)

set(LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::PrintSupport
    ${CURL_LIBRARIES}
)

add_executable(qt ${SOURCES} ${HEADERS_FOR_QOBJECT})
target_link_libraries(qt ${LIBS})