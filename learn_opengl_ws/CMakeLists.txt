cmake_minimum_required (VERSION 2.8)
cmake_policy(VERSION 2.8)

project (LearnOpenGL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

# GLFW libraries
find_package(GLFW3 REQUIRED)
  set(LIBS ${GLFW3_LIBRARY} GL X11 pthread Xrandr Xi dl)
  set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")

# Find GStreamer libraries
find_package(PkgConfig)
pkg_check_modules(GST REQUIRED gstreamer-1.0)

set(CHAPTERS
  hello_traiangle
  shaders
  textures
)

set(hello_traiangle
    1
)

set(shaders
    1
    2
)

set(textures
    1
    2
)

add_library(ADD_LIBS
    "src/stb_image.cpp"
    "src/glad.c"
)
set(LIBS ${LIBS} ADD_LIBS)


include_directories(
    ${CMAKE_SOURCE_DIR}/includes
    ${GST_INCLUDE_DIRS}
)

foreach(PROJ ${CHAPTERS})
    foreach(VER ${${PROJ}})
        file(GLOB SOURCE
            "src/${PROJ}/${PROJ}${VER}.cpp"
        )

        set(NAME "${PROJ}${VER}")
        add_executable(${NAME} ${SOURCE})
        target_link_libraries(${NAME} ${LIBS})

        set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

        # copy shader files to build directory
        file(GLOB SHADERS
                    "src/${PROJ}/*.vs"
                    "src/${PROJ}/*.fs"
                    "src/${PROJ}/*.jpg"
                    "src/${PROJ}/*.png"
        )

        foreach(SHADER ${SHADERS})
                file(COPY ${SHADER} DESTINATION ${CMAKE_SOURCE_DIR}/bin)
        endforeach(SHADER)
    endforeach(VER)
endforeach(PROJ)
