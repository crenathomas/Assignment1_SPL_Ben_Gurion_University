# cmake_minimum_required(VERSION <specify CMake version here>)
project(Assignment1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/cyberdns.h
    include/cyberexpert.h
    include/cyberpc.h
    include/cyberworm.h
    src/cyberdns.cpp
    src/cyberexpert.cpp
    src/cyberpc.cpp
    src/cyberworm.cpp
    src/main.cpp)

add_executable(Assignment1 ${SOURCE_FILES})
