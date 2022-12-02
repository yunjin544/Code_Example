cmake_minimum_required(VERSION 3.0.0)
project(casadi_example VERSION 0.1.0)
add_definitions(-std=c++14)
find_package(casadi REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
    includes/
    ${EIGEN3_INCLUDE_DIRS}
    ${casadi_INCLUDE_DIRS}
)


add_executable(test src/template/casadi_template.cpp)
target_link_libraries(test casadi)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
