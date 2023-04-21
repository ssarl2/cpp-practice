cmake_minimum_required(VERSION 3.10)

if(WIN32)
    message("WIN32")
    # https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#method-3-avoid-use-set
    set(CMAKE_GENERATOR "MinGW Makefiles")
    set(CMAKE_C_COMPILER "C:/ProgramData/chocolatey/bin/gcc.exe")
    set(CMAKE_PREFIX_PATH "C:/ProgramData/chocolatey/lib/curl/tools/curl-8.0.1_1-win64-mingw") # in order to find libraries installed with chocolatey
endif()

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
    src/MenuBarAction.cpp
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

# https://stackoverflow.com/a/54436838
if(MINGW)
    target_link_libraries(qt ${LIBS} -static-libstdc++)
else()
    target_link_libraries(qt ${LIBS})
endif()