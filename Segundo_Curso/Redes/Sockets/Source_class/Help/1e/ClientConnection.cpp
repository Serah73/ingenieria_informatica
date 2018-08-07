//****************************************************************************
//                         REDES Y SISTEMAS DISTRIBUIDOS
//                      
//                     2ª de grado de Ingeniería Informática
//                       
//              This class processes an FTP transactions.
// 
//****************************************************************************



#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cerrno>
#include <netdb.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h> 
#include <iostream>
#include <dirent.h>

#include "common.h"

#include "ClientConnection.h"




ClientConnection::ClientConnection(int s) {
    int sock = (int)(s);
  
    char buffer[MAX_BUFF];

    control_socket = s;
    // Check the Linux man pages to know what fdopen does.
    fd = fdopen(s, "a+");
    if (fd == NULL){
	std::cout << "Connection closed" << std::endl;

	fclose(fd);
	close(control_socket);
	ok = false;
	return ;
    }
    
    ok = true;
    data_socket = -1;
   
  
  
};


ClientConnection::~ClientConnection() {
 	fclose(fd);
	close(control_socket); 
  
}


int connect_TCP( uint32_t address,  uint16_t  port) {
     // Implement your code to define a socket here
    
    char* host = (char*)&address;
    struct sockaddr_in sin;
    struct hostent *hent;
    int s;
    
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    
    if(hent = gethostbyname(host))
        memcpy(&sin.sin_addr, hent->h_addr, hent->h_length);
    else if((sin.sin_addr.s_addr = inet_addr((char*)host)) == INADDR_NONE)
        errexit("No se pudo resolver el nombre \"%s\"\n", address);
        
    s = socket(AF_INET, SOCK_STREAM,0);
    if(s < 0)
        errexit("No se pudo crear el socket: %s\n", strerror(errno));
    
    if(connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0)
        errexit("No se puede conectar con %s: %s\n", host, strerror(errno));
    
    return s;
    return -1; // You must return the socket descriptor.

}






void ClientConnection::stop() {
    close(data_socket);
    close(control_socket);
    parar = true;
  
}





    
#define COMMAND(cmd) strcmp(command, cmd)==0

// This method processes the requests.
// Here you should implement the actions related to the FTP commands.
// See the example for the USER command.
// If you think that you have to add other commands feel free to do so. You 
// are allowed to add auxiliary methods if necessary.

void ClientConnection::WaitForRequests() {
    int sock_aux;
    bool passive = false;
    if (!ok) {
	 return;
    }
    
    fprintf(fd, "220 Service ready\n");
  
    while(!parar) {


 
      fscanf(fd, "%s", command);
      if (COMMAND("USER")) {
	    fscanf(fd, "%s", arg);
	    fprintf(fd, "331 User name ok, need password\n");
      }
      else if (COMMAND("PWD")) {
        fprintf(fd, "257 %s\n", get_current_dir_name());
      }
      else if (COMMAND("PASS")) {
	   fscanf(fd, "%s", arg);
	   
	   if(strcmp(arg,"alumno")==0)
	     fprintf(fd, "230 User logged in.\n");
	   else
	     fprintf(fd, "530 Not logged in.\n");
      }
      else if (COMMAND("PORT")) {
	    unsigned ip[4];
	    unsigned port[2];
	    
	    fscanf(fd, "%d,%d,%d,%d,%d,%d", ip[0], ip[1], ip[2], ip[3], port[0], port[1]);
	    
	    uint32_t uip;
	    uint16_t uport;
	    
	    uip = ip[3] << 24 | ip[2] << 16 | ip[1] << 8 | ip[0];
	    uport = port[1] << 8 | port[0];
	    
	    data_socket = connect_TCP(uip, uport);
	    printf("%d\n", data_socket);
	    
	    fprintf(fd, "200 OK\n");
	  
      }
      else if (COMMAND("PASV")) {
	    struct sockaddr_in PasSock;
        socklen_t PasSocklen = sizeof(PasSock);
        passive = true;

          struct sockaddr_in sin;
          sock_aux = socket(AF_INET,SOCK_STREAM, 0);
          
          if(sock_aux < 0){
            std::cout << "No se pudo crear el socket" << std::endl;
            sock_aux = 0;    
          }
          memset(&sin, 0, sizeof(sin));
          sin.sin_family = AF_INET;
          sin.sin_addr.s_addr = INADDR_ANY;
          
          sin.sin_port = htons(0);
          if(bind(sock_aux, (struct sockaddr *) &sin, sizeof(sin)) < 0)
          errexit("No se pudo bindear: %s\n", strerror(errno));
          if(listen(sock_aux, 5) < 0){
            printf("Fallo en el listen\n");
            sock_aux = 0;
          }
        getsockname(sock_aux,(struct sockaddr *)&PasSock,&PasSocklen);
        uint16_t puerto = PasSock.sin_port;
        std::cout << "Puerto pasivo: " << puerto << std::endl;
        uint8_t port1,port2;
        port1 = puerto >> 8;             
        port2 = puerto;                  
        fprintf(fd,"227 Entering Passive Mode (127,0,0,1,%u,%u)\n",port2,port1);
      }
      else if (COMMAND("CWD")) {
	   fscanf(fd, "%s", arg);
	   chdir(arg);
	   fprintf(fd,"250 Success.\n");
      }
      else if (COMMAND("STOR") ) {
	    fscanf(fd,"%s", arg);
	    FILE* fich = fopen(arg, "wb");
        if(fich == NULL)
        fprintf(fd,"450 File error\n");

        if(passive){
          fprintf(fd,"150 File status okay; about to open data connection\n");  
          struct sockaddr_in ssinSTORE;
          socklen_t slenSTORE = sizeof(ssinSTORE);      
          data_socket = accept(sock_aux,(struct sockaddr *)&ssinSTORE,&slenSTORE);   
        }
        fprintf(fd,"150 File status okay; about to open data connection\n");
        fflush(fd);
        int size_buffer = 512;
        char buffer[size_buffer];
        int datos_recibidos;

        do{  //Ahora realizamos la funciÃ³n que nos interesa, el recv, que recibirÃ¡ los datos por sockets, datos_recibidos nos vale para almacenar el nÃºmero de bytes recibidos
                 //lo cual nos sirve para que cuando este sea distinto al buffer, saber que el fichero ha terminado.
          datos_recibidos = recv(data_socket,buffer,size_buffer,0);
          fwrite(buffer,1,datos_recibidos,fich);
        }while(datos_recibidos == size_buffer);

        close(data_socket);

        fprintf(fd,"226 Closing data connection.\n");
        fclose(fich);

      }
      else if (COMMAND("SYST")) {
	    fprintf(fd, "215 UNIX Type: L8. Remote system type is UNIX. Using binary mode to transfer files.\n"); 
      }
      else if (COMMAND("TYPE")) {
	    fscanf(fd,"%s",arg);
        if(!strcmp(arg,"I"))
        fprintf(fd,"200 Switching to Binary Mode. :\n");
        else if(!strcmp(arg,"A"))
        fprintf(fd,"200 Switching to ASCII mode. :\n");
        else
        fprintf(fd,"501 Syntax error in parameters for argument\n");
      }
      else if (COMMAND("RETR")) {
	    fscanf(fd,"%s",arg);
            FILE* fich = fopen(arg,"rb");
            fprintf(fd,"150 File status okay; about to open data connection\n");
            int datos_enviados;
            int size_buffer = 512;
            char buffer[size_buffer];
             std::cout << "Tamaño del buffer = " << size_buffer << std::endl;
             if(passive){
              struct sockaddr_in ssinSTORE;
              socklen_t slenSTORE = sizeof(ssinSTORE);
              data_socket = accept(sock_aux,(struct sockaddr *)&ssinSTORE,&slenSTORE);
             }
            do{
              datos_enviados = fread(buffer,1,size_buffer,fich);  //Llamada a fread()
              printf("Codigo %d |  %s\n",errno,strerror(errno));
              printf("%d\n",data_socket);
              send(data_socket,buffer,datos_enviados,0);        //Lo mismo que en STOR pero ahora enviamos en lugar de recibir
    	        printf("Codigo %d |  %s\n",errno,strerror(errno));

            }while(datos_enviados == size_buffer);

            close(data_socket);
            fprintf(fd,"226 Closing data connection.\n");
            fclose(fich);
      }
      else if (COMMAND("QUIT")) {
	    fprintf(fd, "221 Service closing control connection\n");
	    stop();
      }
      else if (COMMAND("LIST")) {
	    int io = execlp("ls", "ls", "-l", NULL);
	    fprintf(fd, "223 %d.\n", io);
      }
      else  {
	    fprintf(fd, "502 Command not implemented.\n"); fflush(fd);
	    printf("Comando : %s %s\n", command, arg);
	    printf("Error interno del servidor\n");
	
      }
      
    }
    
    fclose(fd);

    
    return;
  
};


