

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
