#include "Shared_Memory.h"
#include <stdlib.h>

int main(int argc , char* argv[])
{
    shmem_init();
    s_wait(semid[DUTY]);
    *shmem[DUTY] = atoi(argv[1]);
    s_quit(semid[DUTY]);
    return 0;
}