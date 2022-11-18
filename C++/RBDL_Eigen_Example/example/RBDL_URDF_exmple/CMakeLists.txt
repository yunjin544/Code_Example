add_executable(URDF_example URDF_example.cpp)

target_link_libraries(URDF_example
                        #RigidBodyDynamics::Addons
                        ${catkin_LIBRARIES}
                        ${RBDL_LIBRARY}
                        ${RBDL_URDFReader_LIBRARY})

