#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>
#include<string>

bool salir=false;


struct Message {

	//...					// Otros campos del mensaje

	char text[1024];

	//...					// Otros campos del mensaje

};


int main(void){
    int sock= socket(AF_INET,SOCK_DGRAM,0);
    Message message;
    //declaras la estructura sockaddr_in y le das valores
    sockaddr_in address;
    address.sin_family = AF_INET;
    inet_aton("127.0.0.1", &address.sin_addr);
    address.sin_port = htons(6000);
    
    bind(sock, reinterpret_cast<const sockaddr*>(&address),sizeof(address));
    // aquí ya tienes colgado el socket en tu dirección, pero tienes que enviárselo
    // al otro
    sockaddr_in dir_remota;
    dir_remota.sin_family = AF_INET;
    inet_aton("127.0.0.1", &dir_remota.sin_addr);
    dir_remota.sin_port = htons(6001);
    
    
    do{
        std::string mess;
	    std::getline(std::cin, mess);
	    mess.copy(message.text,sizeof(message.text)-1,0);
        
        sendto(sock, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&dir_remota), sizeof(dir_remota));
        if(message.text=="/quit")
            salir=true;
    }while (!salir);
    
    return 0;
}
