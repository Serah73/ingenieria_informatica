#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>
#include<string>
#include<thread>

struct Message {

	//...					// Otros campos del mensaje

	char text[1024];

	//...					// Otros campos del mensaje

};


void enviar(const Message& message, const sockaddr_in& address, bool& salir){
    std::string mess;
    do{                                                       //declaro donde guardare lo que me entre
        std::getline(std::cin, mess);                                           //Recojo de teclado
        if(message.text=="/quit")
            salir= true;
        mess.push_back('\0');
        mess.copy(message.text,sizeof(message.text)-1,0);
        sendto(sock, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&address0), sizeof(address));
    }while (!salir);
}

void recibir(Message& message, sockaddr_in& address, bool& salir){
    socklen_t src_len = sizeof(address);
    while (!salir){
        recvfrom(sock, &message, sizeof(message), 0, reinterpret_cast<sockaddr*>(&address), &src_len);
        std::cout << message.text << "\n";
        std::string mess(message.text);
        if(mess=="/quit")
            salir=true;
    }
}




////////////////main////////////////
int main(void){
    
    bool salir=false;
    Message message;
    
    int sock= socket(AF_INET,SOCK_DGRAM,0);                                     //sock()
    bind(sock, reinterpret_cast<const sockaddr*>(&address),sizeof(address));    //bind()
    
    //declaras la estructura sockaddr_in y le das valores                       //YO
    sockaddr_in address;
    address.sin_family = AF_INET;
    inet_aton("127.0.0.1", &address.sin_addr);
    address.sin_port = htons(6000);

    //declaras la estructura sockaddr_in y le das valores                       //EL OTRO
    sockaddr_in dir_remota;
    dir_remota.sin_family = AF_INET;
    inet_aton("127.0.0.1", &dir_remota.sin_addr);
    dir_remota.sin_port = htons(6001);
    
    std::thread myth1(&enviar,std::ref(message), std::ref(dir_remota), std::ref(salir));
    std::thread myth2(&recibir,std::ref(message), std::ref(dir_remota), std::ref(salir));

    while(!salir);
    
    myth1.join();
    myth2.join();
}