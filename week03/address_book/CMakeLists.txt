cmake_minimum_required(VERSION 3.5)
project(week03)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        test_address_book.c
        address_book.h
        address_book.c)

add_executable(week03 ${SOURCE_FILES})