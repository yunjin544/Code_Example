cmake_minimum_required(VERSION 3.0.0)
project(rbdl_drcl_example VERSION 0.1.0)
add_definitions(-std=c++11)

include_directories(
  # include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  ${RBDL_INCLUDE_DIR}
)

find_package(Eigen3 REQUIRED HINTS ${Eigen3_HINT})
find_package(RBDL REQUIRED)


add_subdirectory(example/Eigen_example)
add_subdirectory(example/RBDL_example)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
