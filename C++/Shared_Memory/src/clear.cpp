#include <sys/shm.h> 
#include <sys/ipc.h> 
#include <stdio.h>

#define KEY_NUM 1234

int main(int argc , char* argv[])
{
    int shmid;
    int *num;
    void *memory_segment = NULL;

    if((shmid = shmget(KEY_NUM,sizeof(int),IPC_CREAT|0666))==-1) return 0;
    if (shmctl(shmid,IPC_RMID,NULL)==-1) return -1;
    printf ("Clear! Done!\n");
    return 0;
}