cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")

# MinGW
# set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")
# set(CMAKE_GENERATOR "MinGW Makefiles")
# set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_FLAGS_DEBUG "-O -g")

# msvc
# set(VCPKG_TARGET_TRIPLET "x64-windows")
# set(CMAKE_GENERATOR "Visual Studio 17 2022")
# set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_FLAGS_DEBUG "-O -g")

project(main)

add_subdirectory(main)
add_subdirectory(tcp)
add_subdirectory(udp)
