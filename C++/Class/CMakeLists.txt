cmake_minimum_required(VERSION 3.0.0)
project(class_example VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(includes/
                    
                    )

add_executable(class_example src/main.cpp)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
