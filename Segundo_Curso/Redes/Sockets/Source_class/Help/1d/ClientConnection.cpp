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
  struct sockaddr_in sin;
  struct hostent *hent;
  int s;
  
  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  memcpy(&sin.sin_addr, &address, sizeof(address));	
  
  
  s = socket(AF_INET, SOCK_STREAM, 0);
  
  if(s<0)
      errexit("No se puede crear el socket: %s\n", strerror(errno));
  
  if(connect(s, (struct sockaddr *) &sin, sizeof(sin)) < 0)
      errexit("No se puede conectar con %d: %s\n", address, strerror(errno));
  return s;


}






void ClientConnection::stop() {
    close(data_socket);
    close(control_socket);
    parar = true;
  
}





    
#define COMMAND(cmd) strcmp(command, cmd)==0
int define_socket_TCP(int port);
// This method processes the requests.
// Here you should implement the actions related to the FTP commands.
// See the example for the USER command.
// If you think that you have to add other commands feel free to do so. You 
// are allowed to add auxiliary methods if necessary.

void ClientConnection::WaitForRequests() {
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
        char dir[100]; 
        getcwd(dir,sizeof(dir)); 
        fprintf(fd, "257 Pathname: %s\n",dir);
      }
      else if (COMMAND("PWD")) {
        char dir[100]; 
        getcwd(dir,sizeof(dir)); 
        fprintf(fd, "257 Pathname: %s\n",dir); 
      }
      else if (COMMAND("PASS")) {
	
	   fscanf(fd, "%s", arg);
	   
	   if (strcmp(arg, "1234") == 0) 
	    fprintf(fd, "239 Password ok\n");
	   
	   else 
	     fprintf(fd, "532 Wrong Password \n");
	   
	  }
      else if (COMMAND("PORT")) {
          int h1,h2,h3,h4,p1,p2;
	  fscanf(fd,"%d,%d,%d,%d,%d,%d", &h1,&h2,&h3,&h4,&p1,&p2);
          uint32_t address = (h4<<24 | h3<<16 | h2<<8 | h1);
          uint16_t port = (p1 << 8 |p2);
          data_socket=connect_TCP(address,port);
          fprintf(fd,"200 Command Ok\n");
      }
      else if (COMMAND("PASV")) {
	  //fscanf(fd,"%s",arg);
          
          
          struct sockaddr_in fsin;
          socklen_t alen = sizeof(fsin);
           printf("hola");
          int passock = define_socket_TCP(0);
           printf("hola1");
          getsockname(passock,(struct sockaddr *)&fsin, &alen);
            
         
              uint16_t port = fsin.sin_port;
              
              int p1 = port >> 8; 
              int p2 = port & 0xFF;
           
          fprintf(fd,"227 Entering passive mode (127,0,0,1,%d,%d)\n",p2,p1);fflush(fd);
          
          data_socket = accept(passock,(struct sockaddr *)&fsin, &alen);
          
      }
      else if (COMMAND("CWD")) {
	   
      }
      else if (COMMAND("STOR") ) {
	    fscanf(fd,"%s", arg);
            
            FILE* fich = fopen(arg,"w+");
            if(fich != NULL)
            {
                char buffer[1024];
                int bytes = 0;
                fprintf(fd, "125 Data connection open; no transfer in progress.\n");fflush(fd);
            while(1)
            {
                printf("recibiendo archivo %d\n",bytes);
                bytes = recv(data_socket, buffer,1024,0);
                fwrite(buffer,1,bytes,fich);
                
                if(bytes != 1024)
                    break;
                
            }
            fclose(fich);
            close(data_socket);
            fprintf(fd,"226 File Receive correctly.\n"); fflush(fd);
            }
            else
                fprintf(fd,"550 File error\n");
            
      }
      else if (COMMAND("SYST")) {
	 fprintf(fd, "215 UNIX Type: L8. Remote system type is UNIX. Using binary mode to transfer files.\n");
	   
      }
      else if (COMMAND("TYPE")) {
	  fscanf(fd, "%s", arg);
		if(strcmp(arg, "A") == 0)
			fprintf(fd,"200 ASCII Type.\n");
		else if(strcmp(arg, "E") == 0)
			fprintf(fd,"200 EBCDIC Type.\n");
		else if(strcmp(arg, "I") == 0)
			fprintf(fd,"200 Image Type.\n");
		else if(strcmp(arg, "L") == 0){
			fscanf(fd, "%s", arg);
			fprintf(fd, "200 Byte size %s.\n",arg);
		}
		else 
			fprintf(fd, "501\n");
      }
      else if (COMMAND("RETR")) {
          fscanf(fd, "%s", arg);
          bool stop_1 = 1;
          FILE* fich = fopen(arg,"r");
          //fprintf(fd, "150 File status ok. about to open data conection\n");
          if(fich != NULL)
          {
              
              fprintf(fd, "125 Data connection open; no transfer in progress.\n");
              char buffer[1024];
            
              int bytes = 0;
          while(stop_1)
          {
              printf("enviando archivo\n");
              bytes = fread(buffer,1, 1024, fich);
              send(data_socket,buffer,bytes,0);
              
              if (bytes != 1024)
                  stop_1=0;
          }
          
          fclose(fich);
          close(data_socket);
          
          fprintf(fd,"226 File receive correctly.\n");fflush(fd);
              
        }
          else 
            fprintf(fd,"550 File error\n");
          printf("salgo del ret\n");
      }
      else if (COMMAND("QUIT")) {
          
	 stop();
         fprintf(fd,"221 Service closing control connection.Logged out if appropriate");fflush(fd);
      }
      else if (COMMAND("LIST")) {
          
          bool parar = 1;
          char dir[100];
          struct dirent *s_dir;
          char buffer[256];
		  char* filename;
          int bytes;
          
          getcwd(dir,sizeof(dir));
          
          DIR* directorio = opendir(".");
          printf("LIST DE :%s\n",dir);
          
              fprintf(fd, "125 List started OK.\n");fflush(fd);
              
              
            
            while((s_dir = readdir(directorio)) != NULL)
            {
				
                filename = s_dir->d_name;
                
                strcat(filename,"\r\n");
                bytes=strlen(filename);
                write(data_socket,filename,bytes);
                
                printf("entra %s\n",filename);
                
                    
              
            }
          
            closedir(directorio);
            close(data_socket);
            fprintf(fd,"250 List Completed Succesfully\n"); fflush(fd);
              
          
        
        
      
      
		}
    }
    fclose(fd);

    
    return;
    
};
