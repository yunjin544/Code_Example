add_executable(Matrix matrix.cpp)
add_executable(Vector vector.cpp)

target_link_libraries(Matrix 
                        Eigen3::Eigen 
                        ${RBDL_LIBRARY}
                        ${RBDL_URDFReader_LIBRARY})

target_link_libraries(Vector 
                        Eigen3::Eigen 
                        ${RBDL_LIBRARY}
                        ${RBDL_URDFReader_LIBRARY})

#install(TARGETS simple_test DESTINATION bin)