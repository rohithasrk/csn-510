#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

int main(int argc, char** argv){
    mqd_t mqd;
    void *ptr;
    size_t len;
    uint32_t prio;

    if(argc!=4)
        perror("usage msgsend <name> <len> <priority>");
    len = atoi(argv[2]);
    prio = atoi(argv[3]);

    mqd = mq_open(argv[1], O_WRONLY);
    ptr = calloc(len, sizeof(char));
    mq_send(mqd, ptr, len, prio);

    exit(0);
}
