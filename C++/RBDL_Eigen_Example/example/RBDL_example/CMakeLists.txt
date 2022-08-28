add_executable(simple_rbdl_example test.cpp)

target_link_libraries(simple_rbdl_example 
                        Eigen3::Eigen 
                        ${RBDL_LIBRARY}
                        ${RBDL_URDFReader_LIBRARY})

#install(TARGETS simple_test DESTINATION bin)