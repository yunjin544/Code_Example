cmake_minimum_required(VERSION 3.0.0)
project(raisim_example VERSION 0.1.0)


find_package(raisim CONFIG REQUIRED)
find_package(Eigen3 REQUIRED HINTS ${Eigen3_HINT})

include_directories ( ${EIGEN3_INCLUDE_DIRS} )


include(CTest)
enable_testing()

add_executable(raisim_example src/main.cpp)

target_link_libraries(raisim_example PUBLIC raisim::raisim pthread)
target_include_directories(raisim_example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
