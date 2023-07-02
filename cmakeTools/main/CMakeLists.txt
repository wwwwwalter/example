

include_directories(
    ${PROJECT_SOURCE_DIR}/include/tcp
    ${PROJECT_SOURCE_DIR}/include/udp
)

set(DIR_EXE_SRCS
    main.cpp
)

find_package(OpenCV CONFIG REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
add_executable(outDebug ${DIR_EXE_SRCS})

# link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(outDebug PRIVATE
    tcp
    udp
    opencv_world
)