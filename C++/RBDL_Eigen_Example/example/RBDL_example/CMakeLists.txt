add_executable(simple_example simple_example.cpp)

target_link_libraries(simple_example 
                        ${RBDL_LIBRARY}
                        ${RBDL_URDFReader_LIBRARY})

#install(TARGETS simple_test DESTINATION bin)