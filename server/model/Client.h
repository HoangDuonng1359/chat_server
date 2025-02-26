#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
    private:
        int socket_fd;
        std::string username;
    public:
        Client(int socket, std::string username);
        int getSocketFd();
        std::string getUsername();
};


#endif // CLIENT_H