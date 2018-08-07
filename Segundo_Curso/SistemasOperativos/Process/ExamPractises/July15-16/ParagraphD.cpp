/*
ENUNCIADO CONVOCATORIA JULIO "d)":

    Permitir que desde la línea de comandos del programa padre se especifique el nombre del archivo donde guardar
el resultado.

////////////1 pto.///////////////
*/

///duda resuelta ---> Notes2.txt "4-"
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
//std open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//fin de las de open

int main(int argc, char *argv[])
{
    int out = open(argv[1], O_WRONLY);
    dup2(out, 1); 
   
    char* user = getenv("USER");
    execlp("/bin/ps", "ps", "-u", user, NULL);
    

    close(out);
}
/*
ejemplo de uso de los argumentos del main por linea de comandos

#include <stdio.h>
#include <cstdlib>

main(int argc, char *argv[])
{
   if(argc!=2) {    //argc es el numero de argumentos que se espera recibir
        printf("Ha olvidado su nombre.\n");
        exit(1); }
    printf("Hola %s\n", argv[1]);   //argv es el array que recibira

}
*/

