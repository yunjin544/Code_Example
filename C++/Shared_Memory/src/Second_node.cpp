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
    printf("shmid : %d\n",shmid);
    if((memory_segment = shmat(shmid,NULL,0)) == (void*)-1) return -1;
    num=(int*)memory_segment;
    for(long i=0 ; i <10000000000; i++)
    {
        printf("i : %ld ,num : %d\r",i,(*num));
    }


    return 0;
}