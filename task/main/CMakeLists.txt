

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