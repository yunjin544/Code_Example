#include <casadi/casadi.hpp>
using namespace casadi;
int main() {
  SX x = SX::sym("x");   
  SX y = SX::sym("y",5); 
  SX Z = SX::sym("Z",4,2); 
  SX B1 = SX::zeros(4,5);
  SX B2 = SX(4,5);
  SX B3 = SX::eye(4);
                           

  SX f = pow(x,2) + 10;
  f = sqrt(f);
  std::cout << "f: " << f << std::endl; // You can check symbolic Expression
  std::cout << "y:" << y << std::endl;
  std::cout << "Z:" << Z << std::endl;
  std::cout << "B1:" << B1 << std::endl;
  std::cout << "B2:" << B2 << std::endl;  
  std::cout << "B3:" << B3 << std::endl;

  
  return 0;
}