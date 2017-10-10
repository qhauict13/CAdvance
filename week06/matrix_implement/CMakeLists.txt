cmake_minimum_required(VERSION 3.5)
project(week06)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        test_graph.c
        graph.c
        graph.h)
set(INCLUDE_DIR ../../lib/inc/)
include_directories(${INCLUDE_DIR})
set(LINK_DIR ../../lib/llib/)
link_directories(${LINK_DIR})

add_executable(week06 ${SOURCE_FILES})

target_link_libraries(week06 fdr utility bt)