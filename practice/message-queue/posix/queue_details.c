#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

int main(int argc, char** argv){
    mqd_t mqd;
    struct mq_attr attr;
    if(argc!=2)
        perror("usage: queue_details <name>");

    mqd = mq_open(argv[1], O_RDONLY | O_CREAT);
    mq_getattr(mqd, &attr);
    printf("max #msgs = %ld, max#bytes/msg = %ld, #currently on queue = %ld\n",
            attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);
    mq_close(mqd);
    exit(0);
}
