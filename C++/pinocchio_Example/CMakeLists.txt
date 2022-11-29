cmake_minimum_required(VERSION 3.0.0)
project(pinocchio_example VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(pinocchio REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
    includes/
    ${EIGEN3_INCLUDE_DIRS}
    ${pinocchio_INCLUDE_DIRS}
)

add_executable(myprogram src/myprogram.cpp)
target_link_libraries(myprogram ${pinocchio_LIBRARIES})


add_subdirectory(example/overview-urdf)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
