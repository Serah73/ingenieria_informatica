#include<sys/socket.h>
#include<iostream>
#include<cerrno>        //variable global errno
#include<cstring>       //cadena del error
#include<system_error>
#include<thread>
#include<atomic>

///127.0.0.1 direccion local
struct Message{
	char text[1024];
};


class Socket{
    private:
    
        int fd_;
        int bind_;
    
    
    public:
        
        //CONSTRUCTOR Y ASIGNACION DE LA DIRECCION
        Socket(const sockaddr_in& address)
        {
            fd_=socket(AF_INET,SOCK_DGRAM,0);
            if (fd_ < 0) {   //Comprobar que se ha creado el socket correctamente
                //throw std::system_error(errno, std::system_category(),"no se pudo crear el socket");
                std::cerr<< "No se pudo crear el socket: " << std::strerror(errno)<< '\n';
            }
            bind_ = bind(fd_, reinterpret_cast<const sockaddr*>(&address),sizeof(address));  // Asignar la dirreccion al socket
            if (bind_ < 0){    //Comprobar que el bind funciona sino manda error
                //throw std::system_error(errno, std::system_category(),"fallo bind");
                std::cerr << "fallo con bind " <<  std::strerror(errno) << '\n';
            }
        }
        
        //DESTRUCTOR
        ~Socket(){}
        
        //ENVIAR MENSAJE
        void send_to(const Message& message, const sockaddr_in& address, bool& salir)
        {
            std::string mess;
            while (!salir){
	            std::getline(std::cin, mess);
                if(mess=="/quit")
                    salir=true;
	            mess.push_back('\0');
	            mess.copy(message.text,sizeof(message.text)-1,0);
        
                sendto(sock, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&address), sizeof(address)));




//////////////////////////////////////////////////COMPROBAR ERROR THROW/CATCH//////////////////////////////////////////////////////////////////////////
                /*
                if (result<0){
                    throw std::system_error(errno, std::system_category(),"fallo sendto");
                }
                */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



            }
        }
        
        //RECIBIR MENSAJE
        void receive_from(Message& message, sockaddr_in& address, bool& salir){
            
            socklen_t src_len = sizeof(address);
            
            while(!salir){
                
                if(message.text="/quit")
                    salir(true);
                // Recibir un mensaje del socket remoto
                /*int result =*/ recvfrom(fd_, &message, sizeof(message), 0, reinterpret_cast<sockaddr*>(&address), &src_len);
                
                if (result<0){
                    //throw std::system_error(errno, std::system_category(),"falló recvfrom");
                    std::cerr<< "Fallo recvfrom " << std::strerror(errno)<< '\n';
                }
                
                                        // Mostrar el mensaje recibido en la terminal
//char* remote_ip = inet_ntoa(remote_address.sin_addr);
//int remote_port = ntohs(remote_address.sin_port);
                
                std::cout << "El sistema " << remote_ip << "," << remote_port << " envió el mensaje: '" << message.text << "'\n";
            }while(!salir);
        }
        

        sockaddr_in make_ip_address(const std::string& ip_address, int port){
            
            //DECLARAMOS LA ESTRUCTURA sockaddr_in COMO local_address Y LE DAMOS VALORES
            sockaddr_in local_address;
            local_address.sin_family = AF_INET;
            local_address.sin_port = port;
            
            if (ip_address.size()==0){
                local_address.sin_addr.s_addr = htonl(INADDR_ANY);
            
                
            }else{
                int aton = inet_aton(ip_address*, local_address.sin_addr*);//devuelve 0 si no es valida la dir y no_cero si es valida
                if(aton==0){                                                    
                     //throw std::system_error(errno, std::system_category(),"fallo ip address");
                    std::cerr<< "Fallo IP adress " << std::strerror(errno)<< '\n';
                }
                else    local_address.sin_addr.s_addr = aton;
            }
            return local_address;
        }

};