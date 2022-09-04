// TODO confirm this
#include <stdlib.h>     // EXIT_FAILURE & htons
#include <unistd.h>     // close(socket)
#include <sys/socket.h> // sock() & AF_INET & SOCK_DGRAM & shutdown
#include <arpa/inet.h>  // sockaddr_in
#include <cstring>      // memset

#include <iostream>

#include "constants.hpp"
#include "data_handler.hpp"
#include "socket.hpp"

void sockethandler::ListenConnections(){
    int sock_fd; 
    
    // Create unbound socket in the specified domain: man socket
    // int socket(int domain, int type, int protocol)
    // domain - specifies the communication domain (AF_INET for IPv4 || AF_INET6 for IPv6)
    // type - type of socket to be created (SOCK_STREAM for TCP || SOCK_DGRAM for UDP)
    // protocol - protocol to be used by socket (0 means default protocol for the address family)
    if( (sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
      throw "socket creation failed";
    }

    // Create structure for server_addr /usr/include/netinet/in.h
    // TODO CHECK sockaddr_in struct!!!!
    //https://stackoverflow.com/questions/19528820/difference-between-sockaddr-and-sockaddr-storage
    struct sockaddr_in server_address;

    // Bind socket to ip address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY); // man htonl - host byte order (unisgned long)-> network byte order
    server_address.sin_port = htons(constants::kDefaultPort);  // host byte order (unsigned short) -> network byte order  // Convert from little to big endian

    // Bind socket with an address and port, so any traffic to that address and port
    // gets handled by the socket

    // int bind(int sockefd, const struct sockaddr *sockaddr, socket_len_t addrlen)
    // sockfd - file descriptor of a socket to be binded
    // addr - structure in which address to be binded to is specified
    // addrlen - size of addr structure
    if( bind(sock_fd, reinterpret_cast<const struct sockaddr *>(&server_address), sizeof(server_address)) < 0){
      throw "bind failed";
    }

    std::cout << " Listening connections on port " << constants::kDefaultPort << "\n";

    // netstat -luvp

    // Create structure for client connecting
    sockaddr_in client_address;
    socklen_t client_length = sizeof(client_address);
    char packet[constants::kMaxPacketSize];
    while(true){
      memset(&client_address, 0, sizeof(client_address));
      memset(&packet, 0 , 50);

      // size_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen)
      // Receive a message from the socket
      // sockfd - file descriptor of socket
      // buf - application buffer in which to receive data
      // len - size of buf application buffer
      // flags - bitwise or of flags to modify socket behaviour
      // src_addr - structure containing source address is returned
      // addrlen - variable in which size of src_addr structure is returned
      int bytes_in = recvfrom(sock_fd, packet, 50, 0, reinterpret_cast<struct sockaddr *>(&client_address), &client_length);
      if(bytes_in < 0){
        throw "No data received";
      }

      // echo "test" | nc -uw1 127.0.0.1 8088
      //std::cout << "Msg: " <<  std::string(packet) << "\n";
      DataHandler::GetPacketId(packet);


    }

    close(sock_fd);
    shutdown(sock_fd, SHUT_RDWR);
  }
