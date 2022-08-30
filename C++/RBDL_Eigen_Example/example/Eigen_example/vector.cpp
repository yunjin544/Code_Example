#include <iostream>
#include <Eigen/Dense>

using namespace Eigen; // namespace 입력을 줄이기 위함 (C++ 문법입니다^^)
using namespace std;   // 주석처리시 ex) std::cout << "Hello world!" ; (or) Eigen::MarixXd A ; ....


int main(int argc, char* argv[])
{
  VectorXf A ;  // A는 동적 벡터 선언
  Vector3f B ;  // B는 정적 벡터 선언 -> Matrix 와 동일함으로 해당 파일 주석 확인해보기
  Vector3d v(1,2,3) ; // 정적 벡터 선언 및 원소 초기화
  //VectorXd w(0,1,2) <- 지원하지 않음
  A = VectorXf(10);

  A(0) = 2.1;
  A(1) = 3.1;  // 원소 하나하나 접근하여 저장하는 방법

  B<<1,2,3 ;     // 행렬과 마찬가지로 시프트 연산자를 이용하여 저장하는 방법
      
  cout << "동적 벡터 A \n" << A << "\n"<< endl;
  cout << "정적 벡터 B \n" << B << "\n"<< endl;
  cout << "정적 벡터 C \n" << v << "\n"<< endl;
  //cout << "동적 벡터 D \n" << w << endl;


  A=B;         // 행렬과 마찬가지로 동적으로 선언된 변수에는 다른 크기의 벡터가 입력될시 그 크기와 값이 같아진다.
  cout << "동적 벡터 A의 변경 \n" << A << "\n"<< endl;



  /********************** Computation Method about Matrix ******************/
  Matrix3f E ;
  E<< 1,2,3,
      4,5,6,
      7,8,9 ;
  
  cout<< "행렬과 벡터 간 곱셈 ([3x3] * [3x1]) \n" <<  E*A << "\n"<< endl;

  Vector3d w(0,1,2) ;

  cout<< "Dot Product : " << v.dot(w) <<  endl;
  cout<< w.dot(v) << "\n"<< endl ;
  
  double dp = v.adjoint()*w;
  cout << "Dot Product via Matrix Product by using adjoint\n" << dp  << "\n"<< endl;
  
  cout << "Cross Product \n" << v.cross(w) << "\n"<< endl;
  
  
  
  
  return 0;
}
