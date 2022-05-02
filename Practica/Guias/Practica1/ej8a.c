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
    int msg = 0;
    if(child == -1)
    {
        perror("Error fork");
    } else {
        while(1)
        {     
            bsend(child,msg);
            wait(NULL);
            if (child==0)
            {
                msg = breceive(get_current_pid());
                msg++;
                bsend(get_current_pid(),msg); 
            }
            msg = breceive(child);
            msg++;
        }
    }
    
    
    return 0;
}
