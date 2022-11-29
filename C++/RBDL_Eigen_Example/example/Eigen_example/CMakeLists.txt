add_executable(Matrix matrix.cpp)
add_executable(Vector vector.cpp)

target_link_libraries(Matrix 
                        ${RBDL_LIBRARY}
                        ${RBDL_URDFReader_LIBRARY})

target_link_libraries(Vector 
                        ${RBDL_LIBRARY}
                        ${RBDL_URDFReader_LIBRARY})

