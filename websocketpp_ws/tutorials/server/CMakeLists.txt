# https://docs.websocketpp.org/md_tutorials_utility_server_utility_server.html
cmake_minimum_required (VERSION 3.1)
project(server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread")

find_package(Boost COMPONENTS system REQUIRED)

set(LIBS ${Boost_LIBRARIES})

set(STEPS
    step1
    step2
)

include_directories(
    ${Boost_INCLUDE_DIRS}
)

# add_library(ADD_LIBS

# )
# set(LIBS ${LIBS} ADD_LIBS)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

foreach(STEP ${STEPS})
    file(GLOB SOURCE
        "src/${STEP}.cpp"
    )
    set(NAME "${STEP}")
    add_executable(${NAME} ${SOURCE})
    target_link_libraries(${NAME} ${LIBS})
endforeach(STEP)
