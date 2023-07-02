

include_directories(${PROJECT_SOURCE_DIR}/include/udp)

set(DIR_LIB_SRCS
    udp.cpp
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/Debug)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/Release)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/RelWithDebInfo)
endif()


add_library(udp SHARED ${DIR_LIB_SRCS})
