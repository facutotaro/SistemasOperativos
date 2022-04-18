#include <signal.h> /* constantes como SIGINT*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    
    int status;
    printf("Soy Abraham \n");
    pid_t homer = fork();
    if (homer == -1)
    {
        perror("Error fork");
        return 1;
    }
    else if(homer == 0)
    {
        printf("Soy homer \n");
        pid_t bart = fork();
        if (bart == 0)
        {
            printf("Soy bart \n");
            exit(-1);
            
        }
        pid_t lisa = fork();
        if (lisa == 0)
        {
            printf("Soy lisa \n");
            exit(-1);
        }
        pid_t maggie = fork();
        if (maggie == 0)
        {
            printf("Soy maggie \n");
            exit(-1);
            
        }
        wait(NULL);
        wait(NULL);
        wait(NULL);
    } 
    wait(NULL);
	return 0;
}
