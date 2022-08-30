#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>

#define KEY_NUM 1234
#define SEM_NUM 1234

union semun{
    int val;
    struct semid_ds *buft;
    unsigned short *array;  
};

void s_wait(int semid){
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;

    if(semop(semid ,&buf,1)==-1){
        printf("<s_wait> Sempo error ! \n");
        return ;
    }
    
}

void s_quit(int semid){
    struct sembuf buf ;
    buf.sem_num =0;
    buf.sem_op = 1 ;
    buf.sem_flg = SEM_UNDO;

    if(semop(semid ,&buf,1)==-1){
    printf("<s_wait> Sempo error ! \n");
    return ;
    }
    
}



int main(){
    int shmid;
    int *num;
    void *memory_seg = NULL;

    int semid;
    union semun sem_union;
    

    if ((shmid = shmget(KEY_NUM , sizeof(int), IPC_CREAT|0666)) == -1 ) 
    {
        printf("Fail to create Shared Memory!");
        return -1;
    }

    if((memory_seg = shmat(shmid,NULL,0))==(void*)-1)
    {
        printf("Fail to load memory segmentation");
        return -1;
    }

    if((semid = semget(SEM_NUM,1,IPC_CREAT|IPC_EXCL|0666)==-1)){
        if((semid = semget(SEM_NUM,0,0))==-1) return -1;
    }
    else{
        sem_union.val = 1;
        semctl(semid,0,SETVAL,sem_union);
    }

    num = (int*)memory_seg;
    for (int i =0 ; i<1000000; i++)
    {
        s_wait(semid);
        (*num) = (*num) + 1 ;
        printf("processing . . . \r");
        s_quit(semid);
    }
    
    printf("\n num : %d\n",(*num));
        

    return 0;
}