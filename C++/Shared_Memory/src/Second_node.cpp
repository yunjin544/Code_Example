#include <sys/shm.h> 
#include <sys/ipc.h> 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "Shared_Memory.h"

void Exit_EventHandler(int sig)
{
    signal(sig,SIG_IGN);
    shmem_clear();

    exit(1);
}


int main(int argc , char* argv[])
{
    shmem_init();

    signal(SIGINT,Exit_EventHandler);

    while(1)
    {

        printf("Slave : %d \r",*shmem[SLAVE_N]);    

    }

    


    return 0;
}