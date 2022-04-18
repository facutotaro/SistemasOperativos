#include <signal.h> /* constantes como SIGINT*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    char* istruccion = argv[1];
    pid_t child = fork();
    if (child == -1)
    {
        perror("Error Fork \n");
    }
    if (child == 0)
    {
        execvp(argv[1],argv+1);
        exit(-1);
    }
    wait(NULL);
    return 0;
}
