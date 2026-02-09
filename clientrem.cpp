#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <stdio.h> // perror is here
#include <unistd.h>
#include <iostream> // exit is here

void die(const char* msg) {
    perror(msg);
    exit(1);
}



int main() {


    // man socket.7 and man ip.2
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // our socket handle
    // AF_INET is IPV4
    // SOCK_STREAM is for TCP
    // 0 is useless to us

    // so no socket has been created yet
    // and when we are changing the options, it will apply to a future created socket
    int val = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    // fd is our socket handle
    // SOL_SOCKET is for listening socket listen socket
    // SO_REUSEADDR is for letting the socket use the same address on restart
        // necessary for TCP communication
    // val and its size and address is passing into resueaddr and is a boolean

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234); // this is the port htons is for changing port to network short - little endianne
    addr.sin_addr.s_addr = htonl(0); // this is a wildcard - takes any ip address and converts to big endianne
    int rv = bind(fd, (const struct sockaddr *)&addr, sizeof(addr));
    // ok so this is making the socket - binding it to the address set inside of our struct
    // and it reads from the actuall 

}