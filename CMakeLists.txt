cmake_minimum_required(VERSION 4.1)
project(esh)

set(CMAKE_CXX_STANDARD 26)

find_package(Boost REQUIRED)

add_executable(esh src/main.cpp)
target_link_libraries(main PRIVATE Boost::boost pthread)
