//****************************************************************************
//                         REDES Y SISTEMAS DISTRIBUIDOS
//                      
//                     2ª de grado de Ingeniería Informática
//                       
//                        Main class of the FTP server
// 
//****************************************************************************

#include <cerrno>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <netdb.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

 #include <unistd.h>


#include <pthread.h>

#include <list>

#include "common.h"
#include "FTPServer.h"
#include "ClientConnection.h"


int define_socket_TCP(int port) {   //En teoría esta HECHO.
   // Include the code for defining the socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0) errexit("Fallo al crear el socket: %S\n", strerror(errno));
    
    struct sockaddr_in address;
    
    memset(&address, 0, sizeof(address));   //inicializar el sockaddr_in a 0(cada uno de los campos).
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
  
    if(bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0)
        errexit("problema con el bind en el puerto: %s\n", strerror(errno));
    
    if(listen(sock, 5) < 0)
        errexit("fallo el listen: %s\n", strerror(errno));
   return sock;
}

// This function is executed when the thread is executed.
void* run_client_connection(void *c) {
    ClientConnection *connection = (ClientConnection *)c;
    connection->WaitForRequests();
  
    return NULL;
}



FTPServer::FTPServer(int port) {
    this->port = port;
  
}


// Parada del servidor.
void FTPServer::stop() {
    close(msock);
    shutdown(msock, SHUT_RDWR);

}


// Starting of the server
void FTPServer::run() {

    struct sockaddr_in fsin;
    int ssock;
    socklen_t alen = sizeof(fsin);
    msock = define_socket_TCP(port);  // This function must be implemented by you.
    while (1) {
	pthread_t thread;
        ssock = accept(msock, (struct sockaddr *)&fsin, &alen);
        if(ssock < 0)
            errexit("Fallo en el accept: %s\n", strerror(errno));
	
	ClientConnection *connection = new ClientConnection(ssock);
	
	// Here a thread is created in order to process multiple
	// requests simultaneously
	pthread_create(&thread, NULL, run_client_connection, (void*)connection);
       
    }

}
