最外层
```cmake
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
```

动态库
```cmake


include_directories(${PROJECT_SOURCE_DIR}/include/tcp)

set(DIR_LIB_SRCS
    tcp.cpp
)


if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/Debug)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/Release)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/RelWithDebInfo)
endif()


add_library(tcp SHARED ${DIR_LIB_SRCS})

```

main
```cmake
include_directories(
    ${PROJECT_SOURCE_DIR}/include/tcp
    ${PROJECT_SOURCE_DIR}/include/udp
)

set(DIR_EXE_SRCS
    main.cpp
)

find_package(OpenCV CONFIG REQUIRED)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/Debug)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/Release)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/RelWithDebInfo)
endif()

add_executable(outDebug ${DIR_EXE_SRCS})

target_link_libraries(outDebug PRIVATE
    tcp
    udp
    opencv_world
)
```
