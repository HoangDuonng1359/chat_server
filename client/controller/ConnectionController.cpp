#include "ConnectionController.h"
#include "../model/User.h"
#include "../model/Connection.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

ConnectionController::ConnectionController(User user, Connection connection) : user(user), connection(connection) {
}

ConnectionController::~ConnectionController() {
}

int ConnectionController::connectToServer() {
    int socket_fd = connection.connectToServer(user);
    if (socket_fd == -1) {
        std::cout << "Failed to connect to server" << std::endl;
        return -1;
    } else {
        send(socket_fd, user.getUsername().c_str(), user.getUsername().length(), 0);
    }
    user.setSocketFd(socket_fd);
    std::cout << "Connected to server" << std::endl;
    return socket_fd;
}

void ConnectionController::disconnect() {
    connection.disconnect(user);
    std::cout << "Disconnected from server" << std::endl;
}