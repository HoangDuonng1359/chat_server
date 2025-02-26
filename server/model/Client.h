#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
    private:
        int socket_fd;
        std::string username;
    public:
        Client();
        Client(int socket, std::string username);
        ~Client();
        int getSocketFd();
        std::string getUsername();

};


#endif // CLIENT_H