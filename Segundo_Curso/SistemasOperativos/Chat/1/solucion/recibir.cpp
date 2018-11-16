#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>
#include<string.h>

bool salir=false;
struct Message {

	//...					// Otros campos del mensaje

	char text[1024];

	//...					// Otros campos del mensaje

};

int main(void){
    int sock= socket(AF_INET,SOCK_DGRAM,0);
    
    //declaras la estructura sockaddr_in y le das valores
    sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    inet_aton("127.0.0.1", &remote_address.sin_addr);
    remote_address.sin_port = htons(6001);

    bind(sock, reinterpret_cast<const sockaddr*>(&remote_address),sizeof(remote_address));

    socklen_t src_len = sizeof(remote_address);
    Message message;
    
    while(!salir){
        recvfrom(sock, &message, sizeof(message), 0, reinterpret_cast<sockaddr*>(&remote_address), &src_len);
        std::cout << message.text << "\n";
	    std::string mess(message.text);
        if(mess=="/quit")
            salir=true;
    };
    
    return 0;
}
