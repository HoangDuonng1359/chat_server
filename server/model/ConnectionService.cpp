#include "ConnectionService.h"
#include "MessageService.h"
#include "../../client/model/Messenger.h" 
#include <iostream>
#include <map>
#include <string>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include "Client.h"


ConnectionService::ConnectionService(int port) : clientManager(ClientManager::getInstance()) {

    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->serverSocket < 0) {
        perror("Error creating socket");
        exit(1);
    } else {
        std::cout << "Server socket created" << std::endl;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
 
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(this->serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding");
        exit(1);
    }
    else {
        std::cout << "Server binded" << std::endl;
    }
    if (listen(this->serverSocket, 5) < 0) {
        perror("Error listening");
        exit(1);
    }
}

ConnectionService::~ConnectionService() {
    close(this->serverSocket);
}

void ConnectionService::start() {
    this->running = true;
    while (this->running) {
        std::cout << "Waiting for connection..." << std::endl;
        acceptConnection();
    }
}

void ConnectionService::stop() {
    this->running = false;
}


void ConnectionService::removeClient(std::string username) {
    int clientSocket = clientManager.getClient(username).getSocketFd();
    close(clientSocket);
    clientManager.removeClient(username);
    std::cout << "Remove connection: " << username << std::endl;
}

void ConnectionService::handleClient(std::string username) {
    char buffer[1024];
    MessageService messageService;
    int clientSocket = clientManager.getClient(username).getSocketFd();
    std::cout << "Handling client: " << username << std::endl;
    while (true) {
        int len = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (len <= 0) {
            std::cout << "Client disconnected: " << username << std::endl;
            removeClient(username);
            break;
        }
        buffer[len] = '\0';
        std::cout << buffer << std::endl;

        
        if(messageService.sendMessage(buffer) == -1){
            std::cout << "Error sending message" << std::endl;
        }
    }
}


void ConnectionService::acceptConnection() {
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(this->serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket < 0) {
        perror("Error accepting connection");
        return;
    }

    char buffer[1024];
    int len = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (len <= 0) {
        perror("Error receiving username");
        close(clientSocket);
        return;
    }
    buffer[len] = '\0';
    std::string username(buffer);
    
    clientManager.addClient(username, Client(clientSocket, username));

    std::cout << "New connection: " << username << std::endl;

    // Tạo thread để xử lý tin nhắn của client
    std::thread(&ConnectionService::handleClient, this, username).detach();
}



void ConnectionService::addClient(int clientSocket, const std::string& username) {
    clientManager.addClient(username, Client(clientSocket, username));
}

