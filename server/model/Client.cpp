#include "Client.h"



Client::Client(int socket_fd, std::string username) {
    this->socket_fd = socket_fd;
    this->username = username;
}

std::string Client::getUsername() {
    return this->username;
}

int Client::getSocketFd() {
    return this->socket_fd;
}

Client::~Client() {
}