#include "Connection.h"
#include "User.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

Connection::Connection(const std::string& ip, int port) {
    this->serverIP = ip;
    this->serverPort = port;
}
// return clientSocket, if connect success
// return -1, if connect fail
int Connection::connectToServer(User& user) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return -1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(this->serverPort);
    serverAddr.sin_addr.s_addr = inet_addr(this->serverIP.c_str());

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connect to server failed" << std::endl;
        return -1;
    } 

    user.setSocketFd(clientSocket);
    return clientSocket;
}

void Connection::disconnect(User& user) {
    close(user.getSocketFd());
    user.setSocketFd(-1);
}