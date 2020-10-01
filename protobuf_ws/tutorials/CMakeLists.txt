# https://developers.google.com/protocol-buffers/docs/cpptutorial
cmake_minimum_required(VERSION 2.8.12)

project(protobuf-tutorials)

find_package(protobuf CONFIG REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(SOURCES
    add_person
    list_people
)

foreach(example add_person list_people)
    set(${example}_SRCS ${example}.cc)
    set(${example}_PROTOS addressbook.proto)

    #Executable setup
    set(executable_name ${example}_cpp)
    add_executable(${executable_name} ${${example}_SRCS} ${${example}_PROTOS})
    target_link_libraries(${executable_name} protobuf::libprotobuf)
    protobuf_generate(TARGET ${executable_name})

endforeach()
