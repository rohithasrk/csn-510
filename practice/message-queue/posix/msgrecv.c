#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

int main(int argc, char **argv){
    int c, flags;
    mqd_t mqd;
    ssize_t n;
    uint32_t prio;
    void *buff;
    struct mq_attr attr;

    flags = O_RDONLY | O_NONBLOCK;

    mqd = mq_open(argv[1], flags);
    mq_getattr(mqd, &attr);
    buff = malloc(attr.mq_msgsize);
    n = mq_receive(mqd, buff, attr.mq_msgsize, &prio);
    printf("read %ld bytes, priority = %u\n", (long) n, prio);
    exit(0);
}
