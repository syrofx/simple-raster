cmake_minimum_required(VERSION 3.21)
project(simple-raster)

set(CMAKE_CXX_STANDARD 20)

if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "C:/Users/ivany/repos/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

add_executable(simple-raster src/main.cpp)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(simple-raster PRIVATE SDL3::SDL3)