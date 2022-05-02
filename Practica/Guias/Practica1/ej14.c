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
    //En el ejercicio original no se asigna el id del child a la memoria compartida
    //(ademas de que es innecesario ya que el padre la conoce). Esta asignacion esta dentro del child,
    //Pero si el padre se ejecuta antes que el hijo no sabe a quien recibir
    pid_t shared_parent_pid;
    mem_share(&shared_parent_pid);
    shared_parent_pid = get_current_pid();
    pid_t child = fork();
    if (child == 0)
    {
        shared_child_pid = get_current_pid();
        bsend(shared_parent_pid, "hola");
        breceive(shared_parent_pid, ...);
        exit(OK);
    }
    else
    {
        breceive(child, ...);
        bsend(child, "chau");
        exit(OK);
    }
}
