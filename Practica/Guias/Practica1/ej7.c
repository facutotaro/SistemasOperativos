#include <signal.h> /* constantes como SIGINT*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 
int main(int argc, char* argv[]) {
    int tiki = 0;
    int taka = 0;

    //suponemos que share_mem permite compartir el puntero a todos los hijos que el procesos cree (no es una syscall real)
    share_mem(tiki); 
    share_mem(taka);
    
    pid_t tikson = fork();
    pid_t takson = fork();

    while (1)
    {
        if(tikson == 0)
        {
            int temp = taka;
            temp++;
            tiki = temp;
            printf("Tikson: tiki %d, taka %d",tiki,taka);
        } else if (takson == 0)
        {
            int temp = tiki;
            temp++;
            taka = temp;
            printf("Takson: tiki %d, taka %d",tiki,taka);
        }
        else {
            while (1)
            {
                /* code */
            }
        }
        
    }
    

    return 0;
}
