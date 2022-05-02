#include <signal.h> /* constantes como SIGINT*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    pid_t child = fork();
    int i = 0;
    if (child == -1)
    {
        perror("Error fork");
        return 1;
    }
    
    // while (1)
    // {
    //     printf("Soy padre: %d \n",i);
    //     if(child == 0)
    //     {
    //         printf("child");
    //     }
    //     wait(NULL);
    //     i++;
    //     printf("Soy padre: %d \n",i);
    // }
    
    for (int i = 0; i < 10; i++)
    {
        printf("Soy padre: %d \n",i);
        wait(NULL);
        if(child == 0)
        {
            printf("child \n");
        }
        printf("flag \n");
    }
    //Porque se corre dos veces   
     
}
