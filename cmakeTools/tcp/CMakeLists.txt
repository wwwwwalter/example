

include_directories(${PROJECT_SOURCE_DIR}/include/tcp)

set(DIR_LIB_SRCS
    tcp.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


add_library(tcp SHARED ${DIR_LIB_SRCS})
