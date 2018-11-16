#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstring>
#include<string>
#include<thread>
#include<atomic>
#include"socket.hpp"

struct Message{
	char text[1024];
};


int main(void){
    
    bool salir(false);
    sockaddr_in local;
    Socket A;
    Message message;
    
    std::cout<<"Dime la IP formato X.X.X.X"<<'\n';
    std::string mess;
    std::getline(std::cin, mess);
    
    std::cout<<"Dime mi puerto"<<'\n';
    int portmio;
    std::cin>>portmio;
    
    local=A.make_ip_address(mess, portmio);
    
    std::cout<<"Dime el puerto destino"<<'\n';
    int portsuyo;
    std::cin>>portsuyo;
    
    remoto=A.make_ip_address(mess, portsuyo);

    std::thread ten(&sent_to, std::ref(mess), std::ref(remoto), std::ref(salir));
	std::thread trec(&receive_from, std::ref(mess), std::ref(local), std::ref(salir));
    
    while(!salir);
    
    ten.join();
    trec.join();
    
}