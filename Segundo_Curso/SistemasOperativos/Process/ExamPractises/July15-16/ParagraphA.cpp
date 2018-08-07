/*
ENUNCIADO CONVOCATORIA JULIO "a)":

    Ejecutar el comando "ps", usando fork() y exec(), pasándole el parámetro '-u' con el nombre del usuario actual para generar
la lista de archivos abiertos por dicho usuario. Recuerda que el nombre del usuario actual lo puedes obtener de las variables de
entorno.

////////////3 ptos.///////////////
*/
#include<iostream>
#include<unistd.h>      //stl que contiene el fork y el execlp(tambien es del dup2)
#include<sys/types.h>       //stl del wait junto la de sys/wait
#include<sys/wait.h>
#include<cstdlib>       //stl getenv(coger la variable de entorno)
#include<cstdio>

int main(void)
{
    pid_t pid = fork(); //pid_t es como un int pero para no confundirlo con uno cualquiera se le asigna otro nombre
    if (pid == 0)       //proceso hijo
    {                   
        char* user = getenv("USER");    //obtienes variable de entorno USER
        execlp("/bin/ps", "ps", "-u", user, NULL);
    }
    else if(pid > 0)        // proceso padre
    {
        wait(NULL);     // el padre esperará a que el hijo termine
        std::cout << "El hijo ha terminado." << std::endl;
        exit(0);
    }
    else 
    {       // error
        perror("fallo en fork()");
        exit(-1);
    }
    return 0;
}