cmake_minimum_required(VERSION 3.23)

set(project "lab3")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp fraction.cpp)

set(${project}_HEADERS
        fraction.hpp)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
endif()
#target_link_libraries(${project} ${CMAKE_SOURCE_DIR}/libplanet.a)