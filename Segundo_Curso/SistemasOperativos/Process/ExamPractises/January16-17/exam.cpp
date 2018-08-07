/*****************************************************************************************************
	Enero de 2016-2017(procesos)
	
		a)	Ejecutar el comando "lsof" pasandole el parámetro -u con el nombre de usuario actual
			para general una lista de archivos abiertos por ese usuario.(3PTOS)
		b)	Conectar el programa "lsof" con "gzip" mediante una tubería para comprimir el resultado
			del primero.(3PTOS)
		c)	Redirigir la salida del "gzip" a un archivo del disco duro para guardar el resultado.(2PTOS)
		d)	Interceptar la señal SIGINT y SIGTERM para matar a todos los procesos hijos en el caso de que
			llegue la señal de interrumpir el programa.(1PTO)
		e)	En cualquier caso el programa debe esperar a que cualquier subproceso termine para evitar que
			queden huérfanos. (1PTO)
**/////////////////////////////////////////////////////////
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<csignal>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<iostream>
#include<signal.h>
#include<errno.h>
#include<cstring>

pid_t child, child2;

void sig_handler(int signum)
{
	if(signum == SIGINT)
	{
		char buff[] = "Señal SIGINT\n";
		write(1, buff, sizeof(buff));
		kill(child, 0);
		kill(child2, 0);
	}
	else if(signum == SIGTERM)
	{
		char buff[] = "Señal SIGTERM\n";
		write(1, buff, sizeof(buff));
		kill(child, 0);
		kill(child2, 0);
	}
}

int main()
{
	
	std::signal(SIGINT, &sig_handler);
	std::signal(SIGTERM, &sig_handler);

	int pipefd[2];

	if (pipe(pipefd))
	{
		printf("ERROR: %s\n", strerror(errno));
	    exit(10);
	}

	child = fork();
	close(pipefd[1]);
	
	if(child == 0) //hijo1
	{
		dup2(1, pipefd[0]);
		char* user = getenv("USER");

		int program = execl("lsof", "-u", user, NULL);
		if (program != 0) perror("fallo execl()");
	}
	else if(child < 0)	//padre
	{
		child2 = fork();
		close(pipefd[0]);
		
		if(child2 == 0)	//hijo2
		{
			dup2(0, pipefd[1]);

			int file = open("exam.txt", O_WRONLY);
			dup2(1, file);
			execl("gzip", pipefd[1], NULL);

		}
		else if(child2 < 0)
		{
			wait(NULL);	//esperar a que muera un hijo(salta independientemente de si es hijo1 o hijo2)
			wait(NULL);	//por eso tenemos doble wait, para asegurarnos de no dejar al restante huerfano

			std::cout << "han terminado los hijos" << std::endl;

			exit(0);
		}
		else
		{
			if( (kill(child, 0))) printf("murio el hijo\n");
			else printf("ERROR: %s\n", strerror(errno));
		}
	}else
	    printf("ERROR: %s\n", strerror(errno));
}