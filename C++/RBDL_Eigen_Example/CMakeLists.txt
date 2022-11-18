cmake_minimum_required(VERSION 3.0.0)
project(rbdl_drcl_example VERSION 0.1.0)
add_definitions(-std=c++11)


list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(Eigen3 REQUIRED)
find_package(RBDL REQUIRED)

include_directories(
  # include
  ${EIGEN3_INCLUDE_DIRS}
  ${RBDL_INCLUDE_DIR}
)

add_subdirectory(example/Eigen_example)
add_subdirectory(example/RBDL_example)
add_subdirectory(example/RBDL_URDF_exmple)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
