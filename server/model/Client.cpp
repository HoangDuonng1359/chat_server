#include "Client.h"



Client::Client(int socket_fd, std::string username) {
    this->socket_fd = socket_fd;
    this->username = username;
}


Client::Client() {
    this->socket_fd = -1;
    this->username = "";
}

std::string Client::getUsername() {
    return this->username;
}

int Client::getSocketFd() {
    return this->socket_fd;
}

Client::~Client() {
}