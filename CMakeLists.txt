cmake_minimum_required(VERSION 3.21)
project(simple-raster)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Setting vcpkg toolchain...")
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/ivany/repos/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.h
)

add_executable(simple-raster ${SOURCES})

message("Enabling warnings...")
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(simple-raster PRIVATE SDL3::SDL3)