#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char** argv){
    int i, shmid, msqid;
    for(i=0; i<10; i++){
        msqid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
        shmid = shmget(IPC_PRIVATE, 64*1024, 0666 | IPC_CREAT);
        printf("msqid = %d shmid %d\n", msqid, shmid);
        msgctl(msqid, IPC_RMID, NULL);
    }
    exit(0);
}
