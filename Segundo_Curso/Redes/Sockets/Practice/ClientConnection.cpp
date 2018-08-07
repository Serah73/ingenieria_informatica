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

//#include "FTPServer.cpp"


ClientConnection::ClientConnection(int s) {
    int sock = (int)(s);
  
    char buffer[MAX_BUFF];

    control_socket = s;
    // Check the Linux man pages to know what fdopen does. 
    fd = fdopen(s, "a+");
    //fdopn se encarga de redirigir el flujo a "a+" añadir al final del archivo y (HECHO)
    //si este no existe lo crea. (HECHO)
    if (fd == NULL){
	    std::cout << "Connection closed" << std::endl;
    	fclose(fd);
    	close(control_socket);
    	ok = false;
	    return ;
    }
    
    ok = true;
    data_socket = -1; //data = vacio
    passive = false;
   
  
  
};


ClientConnection::~ClientConnection() {
 	fclose(fd);
	close(control_socket); 
  
}


int connect_TCP( uint32_t address,  uint16_t  port) {

    struct sockaddr_in sin;
    //struct hostent *hent;   
  
    //inicializar a 0 la estructura;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    
    //copiar en sin.sin_addr, la direccion "address"
    memcpy(&sin.sin_addr, &address, sizeof(address));	
  
    int sock = socket(AF_INET, SOCK_STREAM, 0);
  
    if(sock < 0)
        errexit("No se pudo crear el socket: %s\n", strerror(errno));
  
    if(connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0)
        errexit("No se pudo conectar con %d: %s\n", address, strerror(errno));
    
    return sock;
///////////////////////////////////////////////////////////////////////////////    
                                                                             //
    // Implement your code to define a socket here                           //
    //HACER                                                                  //
    // You must return the socket descriptor.                                //
///////////////////////////////////////////////////////////////////////////////

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
    if (!ok) 
    {
	    return;
    }
    
    fprintf(fd, "220 Service ready\n");
  
    while(!parar) 
    {
        fscanf(fd, "%s", command);
       
        if (COMMAND("USER")) {
            fscanf(fd, "%s", arg);
            fprintf(fd, "331 User name ok, need password\n");
        }
        else if (COMMAND("PWD")) {
	        char dir[MAX_BUFF]; 
            
            getcwd(dir,sizeof(dir));   //getcwd se encarga de obtener el PATH del directorio actual.
            fprintf(fd, "257 Pathname: %s\n",dir);      //257 pathname created
        }
        
        
        else if (COMMAND("PASS")) {
            fscanf(fd, "%s", arg);
            
            if(strcmp(arg, "alumno") == 0)                  //si la password es "alumno" sera correcta, strcmp es el encargado de comprobar
                fprintf(fd, "230 password: Correct\n");     //230 user logged
                
            else    fprintf(fd, "530 password: Error");     //530 not logged in
        }
        
        
        else if (COMMAND("PORT")) {
	        int h1,h2,h3,h4,p1,p2;
	        fscanf(fd,"%d, %d, %d, %d, %d, %d", &h1 ,&h2 ,&h3 ,&h4 ,&p1 ,&p2);
            uint32_t address = (h4<<24 | h3<<16 | h2<<8 | h1);      //recordamos que es la direccion
            uint16_t port = (p1 << 8 |p2);                          //recordamos que uint16 es el puerto
        
            data_socket = connect_TCP(address,port);
        
            fprintf(fd,"200 Command(port) okay\n");       //200 working directory changed
        }
        
        
        else if (COMMAND("PASV")) {
	        struct sockaddr_in PasSock;
            socklen_t PasSocklen = sizeof(PasSock);
            passive = true;

            struct sockaddr_in sin;
            int sock_aux = socket(AF_INET,SOCK_STREAM, 0);
          
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
                fprintf(fd, "Fallo en el listen\n");
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
	        chdir(arg);                         //llamada del sistema para cambiar el path del "arg" sin cambiar el path del directorio
	        fprintf(fd,"250 Success.\n");       //250 Requested file action okay, completed.
        }
        
        
        else if (COMMAND("STOR")) {    //acepta datos transferidos y los almacena.
    	   
            fscanf(fd, "%s", arg);

            FILE* archivo = fopen(arg,"wb");

            if (!archivo){
                fprintf(fd, "450 Requested file action not taken.\n");
                close(data_socket);
            }

            else{

                fprintf(fd, "150 File status okay; about to open data connection.\n");
                fflush(fd);

                struct sockaddr_in sa;
                socklen_t sa_len = sizeof(sa);
                char buffer[MAX_BUFF];
                int k;

                if (passive)
                    data_socket = accept(data_socket,(struct sockaddr *)&sa, &sa_len);

                do{
                    k = recv(data_socket, buffer, MAX_BUFF, 0);
                    fwrite(buffer, sizeof(char) , k, archivo);

                } while (k == MAX_BUFF);

                fprintf(fd,"226 Closing data connection. Requested file action successful.\n");
                fclose(archivo);
                close(data_socket);
	       }
            
        }
        
        
        else if (COMMAND("SYST")) {
            //215 name system type
	        fprintf(fd, "215 UNIX Type: L8.\nRemote system type is UNIX. Using binary mode to transfer files.\n");
        }
        else if (COMMAND("TYPE")) {
	        fscanf(fd,"%s",arg);
    
            if(strcmp(arg,"I") == 0)
                fprintf(fd,"200 Switching to Binary Mode:\n");
    
            else if(strcmp(arg,"A") == 0)
                fprintf(fd,"200 Switching to ASCII mode:\n");
            
            else if(strcmp(arg, "E") == 0)
                fprintf(fd, "200 Switching to EBCDIC mode:\n");
            
            else if (!strcmp(arg,"L"))
                fprintf(fd, "200 Switching to Tenex mode.\n");
    
            else
            fprintf(fd,"501 Syntax error in parameters or arguments.'\n");
            //501 Syntax error in parameters or arguments.
        }
        else if (COMMAND("RETR")) {
            fscanf(fd, "%s", arg);
            bool final = false;
            
            FILE* archivo = fopen(arg,"rb");
            
            if(!archivo)
            {
                fprintf(fd,"550 File error\n");
                close(data_socket);
            }    
            else{

                fprintf(fd, "125 Data connection already open; transfer starting\n");
                
                struct sockaddr_in sock;
                char buffer[MAX_BUFF];
                int bytes = 0;
                socklen_t socklen = sizeof(sock);
                
                
                if (passive){
                    data_socket = accept(data_socket,(struct sockaddr *)&sock, &socklen);
                }
                
                while(!final)
                {
                    fprintf(fd, "Sending file\n");
                    bytes = fread(buffer, sizeof(char), MAX_BUFF, archivo);
                    send(data_socket, buffer, bytes, 0);
                  
                    if (bytes != MAX_BUFF)  final = true;
                }
                
                fprintf(fd,"226 Closing data connection.\n");          

                fclose(archivo);
                close(data_socket);

                fflush(fd);
            }
        }
        else if (COMMAND("QUIT")) {
    	    fprintf(fd, "221 Service closing control connection.\n"); //221 Service closing control connection.
	        fflush(fd);
	        stop();
        }
        
        else if (COMMAND("LIST")) {

            bool parar = 1;
            char dir[100];
            struct dirent *s_dir;
            char buffer[256];
		    char* filename;
            int bytes;
          
            getcwd(dir,sizeof(dir));
          
            DIR* archivo = opendir(".");
            printf("LIST DE :%s\n",dir);
          
            fprintf(fd, "125 List started OK.\n");fflush(fd);
            
            while((s_dir = readdir(archivo)) != NULL)
            {
				
                filename = s_dir->d_name;
                
                strcat(filename,"\r\n");
                bytes=strlen(filename);
                write(data_socket,filename,bytes);
                
                printf("entra %s\n",filename);
            }
          
            closedir(archivo);
            close(data_socket);
            fprintf(fd,"250 List Completed Succesfully\n");
            fflush(fd);
        }
      
    }
    
    fclose(fd);

    
    return; 
  
};
