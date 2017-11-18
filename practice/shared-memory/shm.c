#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(int argc, char* argv[]){
    key_t key;
    int shmid;
    char *data;
    int mode;

    if(argc > 2){
        fprintf(stderr, "usage: shm [data_to_write]\n");
        exit(1);
    }

    if((key = ftok("shm.c", 'R')) == -1){
        perror("ftok");
        exit(1);
    }

    if((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1){
        perror("shmget");
        exit(1);
    }

    data = shmat(shmid, (void *)0, 0);
    if(data == (char *)(-1)){
        perror("shmat");
        exit(1);
    }

    if(argc == 2){
        strncpy(data, argv[1], SHM_SIZE);
        printf("Writing to segment: \"%s\"\n", data);
    } else
        printf("segment contains: \"%s\"\n", data);

    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
