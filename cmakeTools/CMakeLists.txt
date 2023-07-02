cmake_minimum_required(VERSION 3.10)


set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg/scripts/buildsystems/vcpkg.cmake")
# set(VCPKG_TARGET_TRIPLET "x64-windows")
set(CMAKE_GENERATOR "MinGW Makefiles")

project(main)

add_subdirectory(main)
add_subdirectory(tcp)
add_subdirectory(udp)
