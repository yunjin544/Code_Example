#include <iostream>
#include <rbdl/rbdl.h>

using namespace RigidBodyDynamics;
using namespace RigidBodyDynamics::Math;
using namespace std;

int main (int argc, char* argv[]) {
  rbdl_print_version();

  Model *model = NULL;  // model 포인터 변수 선언

  unsigned int body_a_id, body_b_id, body_c_id;;   // 바디의 id 번호를 저장할 UINT형 변수 선언
  Body body_a, body_b, body_c;                     // 각 바디에 대한 Mass , CoM , gyration_radii 를 저장할 수 있는 구조체 생성
                                                   // 3번째 파라미터는 C++ 오버로딩에 의해서 Vector3d일경우 CoM에서 회전 반경 , Matrix3d일 경우 CoM의 Inertia Matrix
  Joint joint_a , joint_b, joint_c;                // 각 조인트에 대한 정보를 담을 수 있는 구조체 생성

  model = new Model() ;

  body_a = Body (1., Vector3d (0.5, 0., 0.0), Vector3d (1., 1., 1.));  // Body(dobule Mass , Vector3d COM , Vector3d radii_gyration )
  joint_a = Joint(JointTypeRevolute,Vector3d (0., 0., 1.));            // Joint ( JonitTypeDefine, SpatialVector_axis)
  body_a_id = model->AddBody(0, Xtrans(Vector3d(0., 0., 0.)), joint_a, body_a,"First"); // AddBody(usigned int FixedBodyid , 이게 햇갈림 x축으로 병진 같은데 Xtran(), Joint joint , Body body)
    
  body_b = Body (1., Vector3d (0., 0.5, 0.), Vector3d (1., 1., 1.));
  joint_b = Joint (JointTypeRevolute,Vector3d (0., 0., 1.));
  body_b_id = model->AddBody(body_a_id, Xtrans(Vector3d(1., 0., 0.)), joint_b, body_b,"second");
    
  body_c = Body (0., Vector3d (0.5, 0., 0.), Vector3d (1., 1., 1.));
  joint_c = Joint (JointTypeRevolute,Vector3d (0., 0., 1.));
  body_c_id = model->AddBody(body_b_id, Xtrans(Vector3d(0., 1., 0.)), joint_c, body_c,"last");

  VectorNd Q = VectorNd::Zero (model->q_size);        // 각 Q,QDOT Tau, QDDOT 벡터를 구하기 위한 사이즈를 구하고
  VectorNd QDot = VectorNd::Zero (model->qdot_size);  // 이를 저장할 수 있도록 동적행렬을 구성함
  VectorNd Tau = VectorNd::Zero (model->qdot_size);
  VectorNd QDDot = VectorNd::Zero (model->qdot_size);

  cout << model->GetBodyId("last")<<endl;
  Tau << 1,2,3 ;
  
  ForwardDynamics (*model, Q, QDot, Tau, QDDot);     //ForwardDynamic ( Known : Tau , Uknown : Q,Qdot,Qddot)

  std::cout << QDDot.transpose() << std::endl;

  delete model;    // new 를 이용한 동적할당을 해제함
  
  return 0;
}