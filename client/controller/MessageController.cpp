#include "../model/User.h"
#include "../model/Messenger.h"
#include "MessageController.h"
#include "iostream"
#include "ctime"
#include "iomanip"
#include <sstream>
#include "string"
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <thread>



MessageController::MessageController() {
}

void MessageController::sendMessage(std::string sender_id, int socketFd, std::string receiver_id, std::string content, std::string type) {
    Messenger messenger;
    messenger.setSenderId(sender_id);
    messenger.setReceiverId(receiver_id);
    messenger.setContent(content);
    messenger.setType(type);
    std::time_t now = time(0);
    std::tm* localTime = std::localtime(&now); 

    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    messenger.setCreatedAt(oss.str());

    if(send(socketFd, messenger.toString().c_str(), messenger.toString().length(), 0) != -1){
        std::cout << "Message sent!" << std::endl;
    } else {
        std::cout << "Failed to send message!" << std::endl;
    }
}

void MessageController::receiveMessage(int socketFd) {
    if(socketFd == -1){
        std::cout << "Failed to receive message!" << std::endl;
        return;
    }
    char buffer[1024] = {0};
    while(true){
        int valread = read(socketFd, buffer, 1024);
        if(valread <= 0){
            std::cout << "Disconnected from server" << std::endl;
            break;
        } else {
            std::cout <<"\n" <<buffer << std::endl;
        }
    }
}

void MessageController::startReceivingMessage(int socketFd) {
    std::thread t(&MessageController::receiveMessage, this, socketFd);
    t.detach();
}
