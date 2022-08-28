#include <iostream>
#include <Eigen/Dense>

using namespace Eigen; // namespace 입력을 줄이기 위함 (C++ 문법입니다^^)
using namespace std;   // 주석처리시 ex) std::cout << "Hello world!" ; (or) Eigen::MarixXd A ; ....


int main(int argc, char* argv[])
{

    /********************** How to Declare Matrix ***********************/
  
    MatrixXd A;      // MatrixXd : double형 동적 행렬 , MatrixXi : int형 동적행렬 , ...     
    Matrix3i C;      // Matrix3f : float형 3X3행렬  , Matrix2i : int형 2x2행렬 , ....
    MatrixXd Result;

    A = MatrixXd(3,3);  // 동적행렬은 생성자로 인한 선언에서는 행렬 크기를 사용하지 않지만
                        // 시프트 연산자(<<)으로 행렬 원소값을 넣을 경우에는 행렬 크기를 선언해야한다. 
    
    MatrixXd B(2,2); // 생성할때 바로 크기를 입력할 수도 있다
    

    A<<1,2,3,
       4,5,6,           // 동적 행렬은 행렬의 크기가 입력 전에는 시프트 연산자(<<)를 사용할 수 없다.
       7,8,9;           // 동적 행렬은 행렬의 크기가 입력된 후에는 << 시프트 연산자를 통해서 순차적으로 행을 채우며 입력할 수 있다.

    C<< 1,2,3,
        4,5,6,
        7,8,9;          // 정적으로 선언된 행렬은 크기가 이미 입력된 것이므로 바로 값의 대입 가능하다.


    B=A;                // 동적 행렬 선언이므로 크기 2X2인 행렬으로 초기 선언을 했더라도 3X3의 행렬을 저장가능하다.

    cout<<"동적 행렬 A\n"<<A<<"\n"<<endl;

    cout<<"정적 행렬 C \n"<<C<<"\n"<<endl;

    /********************** Computation Method about Matrix ******************/

    Result = A+B;       
    cout<<"덧셈 연산\n"<<Result<<"\n"<<endl;

    
    Result = A-B;       
    cout<<"뺄셈 연산\n"<<Result<<"\n"<<endl;

    Result = A*B;       // 행렬간 곱셈은 기존과 동일한 곱셈 연산자를 이용하면 된다.
    cout<<"곱셈 연산\n"<<Result<<"\n"<<endl;
    
    Result = A.inverse();
    cout<<"인버스(역행렬)\n"<<Result<<"\n"<<endl;

    Result = A.transpose();
    cout<<"전치(Transpose)\n"<<Result<<"\n"<<endl;
    cout<<"주의 사항 : Transpose를 이용할 경우 재귀적 방법(a=a.transpose;) 으로 프로그래밍하면 안된다(공식문서) 대신 a.transposeInPlace()이용 "<<endl;

    A.transposeInPlace();
    cout<<"예시\n"<<A<<"\n"<<endl;
    


  
    /********************** Other Method about Matrix ***********************/

    MatrixXd D(2,4);

    cout<<"행 크기 추출\n"<<D.rows()<<"\n"<<endl;

    cout<<"열 크기 추출\n"<<D.cols()<<"\n"<<endl;

    cout<<"행렬 원소 개수\n"<<D.size()<<"\n"<<endl;

        
    return 0;
}
