cmake_minimum_required(VERSION 3.5)
project(week031)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        test_symbol_tables.c
        symbol_table.c
        symbol_table.h)

add_executable(week031 ${SOURCE_FILES})