cmake_minimum_required(VERSION 3.17)
project(generic_linked_list C)

set(CMAKE_C_STANDARD 11)
include_directories(src)

add_executable(generic_linked_list src/main.c src/list.c src/consumers.c)
add_executable(list-tests test/test-framework.c test/list-test.c src/list.c src/consumers.c)