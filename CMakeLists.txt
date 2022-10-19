cmake_minimum_required(VERSION 3.20.2)
project(typId CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter")

find_package(fmt CONFIG REQUIRED)

add_executable(main test.cpp)

target_link_libraries(main
    PUBLIC
        fmt::fmt
)