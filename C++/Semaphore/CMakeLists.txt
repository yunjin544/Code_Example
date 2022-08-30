cmake_minimum_required(VERSION 3.0.0)
project(semaphore VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(node_1 src/node_1.cpp)
add_executable(node_2 src/node_2.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
