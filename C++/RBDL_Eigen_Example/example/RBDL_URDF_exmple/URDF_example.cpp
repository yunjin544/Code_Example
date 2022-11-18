#include <iostream>
#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <rbdl/rbdl.h>
#include <rbdl/rbdl_utils.h>
#include <rbdl/addons/urdfreader/urdfreader.h>
#include <stdio.h>
#include <time.h>

using namespace std;


int main (int argc, char* argv[]) {

  clock_t start, end;
  double result;
 
  RigidBodyDynamics::Model robotModel;
  string str ="/home/yunjin/Documents/cpp_ws/Code_Example/C++/RBDL_Eigen_Example/example/URDF/simple_manipulator.urdf";
  RigidBodyDynamics::Addons::URDFReadFromFile(str.c_str(), &robotModel, false);
  cout << "Your Robot's DOF : " <<(size_t)robotModel.dof_count << endl;

  RigidBodyDynamics::Math::VectorNd Q = RigidBodyDynamics::Math::VectorNd::Constant((size_t)robotModel.dof_count, 0.); // 로봇의 관절 공간 위치 벡터[q1,q2, ... qn].T 
  RigidBodyDynamics::Math::MatrixNd J = RigidBodyDynamics::Math::MatrixNd::Zero(3, (size_t)robotModel.dof_count); // 로봇의 자코비안 Matrix

  int end_effector_id = robotModel.GetBodyId("Link3");

  Eigen::Vector3d pos, end_eff;
  pos.setZero();
  pos << -0.05, 0.0, -0.3295;
   RigidBodyDynamics::UpdateKinematicsCustom(robotModel, &Q, NULL, NULL);
    RigidBodyDynamics::CalcPointJacobian(robotModel, Q, end_effector_id, pos, J, false);
    end_eff.segment<3>(0) = RigidBodyDynamics::CalcBodyToBaseCoordinates(robotModel, Q, end_effector_id, pos, false);

    std::cout << "Jacobian" << std::endl;
    std::cout << J << std::endl;

    std::cout << "end_effector position" << std::endl;
    std::cout << "end_effector x : " << end_eff(0) << std::endl;
    std::cout << "end_effector y : " << end_eff(1) << std::endl;
    std::cout << "end_effector z : " << end_eff(2) << std::endl;

    while (true)
    {
        Q = RigidBodyDynamics::Math::VectorNd::Random((size_t)robotModel.dof_count);
        RigidBodyDynamics::UpdateKinematicsCustom(robotModel, &Q, NULL, NULL);
        RigidBodyDynamics::CalcPointJacobian(robotModel, Q, end_effector_id, pos, J, false);
        end_eff.segment<3>(0) = RigidBodyDynamics::CalcBodyToBaseCoordinates(robotModel, Q, end_effector_id, pos, false);

    }

  return 0;
}