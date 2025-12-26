cmake_minimum_required(VERSION 3.31)
project(esh)

set(CMAKE_CXX_STANDARD 26)

find_package(Boost REQUIRED)

add_executable(esh 
    src/main.cpp
    src/shell.cpp
    src/autocompletion.cpp
)
target_link_libraries(esh PRIVATE Boost::boost pthread)
