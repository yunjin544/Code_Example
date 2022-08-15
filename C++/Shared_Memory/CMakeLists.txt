cmake_minimum_required(VERSION 3.0.0)
project(shared_memory VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(First_node src/First_node.cpp)
add_executable(Second_node src/Second_node.cpp)
add_executable(Clear src/clear.cpp)