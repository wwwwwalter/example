cmake_minimum_required(VERSION 3.20.0)

project(main)

include_directories(sub1)
include_directories(sub2)

FILE(GLOB SUB1_FILES "sub1/*.h" "sub1/*.cpp")
FILE(GLOB SUB2_FILES "sub2/*.h" "sub2/*.cpp")
FILE(GLOB MAIN_FILES "main/*.h" "main/*.cpp")

source_group(sub1 FILES ${SUB1_FILES})
source_group(sub2 FILES ${SUB2_FILES})
source_group(main FILES ${MAIN_FILES})





add_executable(main ${MAIN_FILES} ${SUB1_FILES} ${SUB2_FILES})