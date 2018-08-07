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

int main()
{
    pid_t proceso = fork();
    
    if(proceso == 0)    //el hijo
    {
        char* usuario = getenv("USER");
        
    }
    
}