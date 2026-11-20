cmake_minimum_required(VERSION 3.25)
project(MyApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE PROJECT_HEADERS CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_executable(MyApp
        src/main.cpp
        ${PROJECT_HEADERS}
        src/core.h
)


target_include_directories(MyApp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_compile_options(MyApp PRIVATE -Wall -Wextra)