/*
ENUNCIADO CONVOCATORIA JULIO "b)":

    Redirigir la salida de "ps" a un archivo del disco duro para guardar el resultado.

////////////2 ptos.///////////////
*/

#include<iostream>
#include<unistd.h>      //contiene el fork y el execlp
#include<sys/types.h>       //contiene wait junto la de sys/wait
#include<sys/wait.h>
#include<cstdlib>       //getenv
#include<cstdio>
#include<sys/stat.h>        //parte del open
#include<fcntl.h>       //parte del open

int main(void)
{
    char* user = getenv("USER");
    int fd = open("apartadoB.txt", O_WRONLY);
    
    dup2(fd, STDOUT_FILENO);
    execlp("/bin/ps", "ps", "-u", user, NULL);
    
    return 0;
}