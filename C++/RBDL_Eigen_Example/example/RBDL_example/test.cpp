#include <iostream>
#include <rbdl/rbdl.h>
  
int main (int argc, char* argv[]) {
  rbdl_check_api_version (RBDL_API_VERSION);
  rbdl_print_version()	;
  
  return 0;
}