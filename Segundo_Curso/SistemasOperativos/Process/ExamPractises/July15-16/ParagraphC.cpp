/*
ENUNCIADO CONVOCATORIA JULIO "b)":

    Interpretar la señal SIGINT y SIGTERM para matar a todos los procesos hijos en caso de que llegue la orden de interrumpir el programa.
El proceso no puede terminar hasta que todos los hijos no lo hagan.

////////////2 ptos.///////////////
*/
#include<sys/types.h>
#include<csignal>
#include<unistd.h>
#include<ostream>

//typedef (*sighandler_t) (int)

//sighandler_t signal(int signum, sighandler_t handler);

bool quit = false;

void int_signal_handler(int signum)
{
    if(signum == SIGINT)
    {
        char buff[] = "Señal SIGINT captada\n";
        write(1, buff, sizeof(buff));
        quit = true;
    }
    else if(signum == SIGTERM)
    {
        char buff[] = "Señal SIGTERM captada\n";
        write(1, buff, sizeof(buff));
        quit = true;
    }
};

int main(void)
{
    std::signal(SIGINT, &int_signal_handler);
    std::signal(SIGTERM, &int_signal_handler);
    while(!quit);
}