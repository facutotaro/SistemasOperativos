#include <signal.h> /* constantes como SIGINT*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    pid_t* child1 = fork();
    pid_t* child2 = fork();
    share_mem(child1);
    int msg = 0;
    while (1)
    {
        //¿Como hago para que los hijos esperen al padre y que ellos se esperen entre si?
        bsend(child1, msg);
        printf("El padre envia a hijo1 el valor %d",msg);
        wait(NULL);
        wait(NULL);
        if (*child1 == 0)
        {
            msg = breceive(get_current_pid());
            msg++;
            bsend(*child2, msg);
            printf("El hijo1 envia a hijo2 el valor %d",msg);
            exit(-1);
        }
        if (*child1 == 0)
        {
            msg = breceive(child1);
            msg++;
            bsend(get_current_pid(), msg);
            printf("El hijo2 envia a padre el valor %d",msg);
            exit(-1);
        }
        msg = breceive(child2);
        msg++;
    }

    return 0;
}