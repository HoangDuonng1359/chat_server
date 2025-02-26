#include "model/User.h"
#include "controller/ConnectionController.h"
#include "controller/MessageController.h"
#include<iostream>
#include <string>
int main() {
    User user;
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;
    user.setUsername(username);
    Connection connection("127.0.0.1", 8080);
    ConnectionController connectionController(user, connection);
    int socket_fd = connectionController.connectToServer();
    user.setSocketFd(socket_fd);
    
    MessageController messageController;
    messageController.startReceivingMessage(user.getSocketFd());
    
    bool isSending = true;
    while(isSending){
        std::string choice;
        std::cout << "Do you want to send message? (y/n): ";
        std::cin >> choice;
        if(choice == "n"){
            isSending = false;
            break;
        }
        std::string message;
        std::string receiverId;

        int choiceType;
        std::cout << "1. Send to user\n2. Send to group\n";
        std::cin >> choiceType;

        if(choiceType == 1){
            std::cout << "Enter receiverId: ";
            std::cin >> receiverId;
            std::cout << "Enter message: ";
            getline(std::cin >> std::ws, message);
            messageController.sendMessage(user.getUsername(), user.getSocketFd(), receiverId, message, TOCLIENT);
        } else {
            std::cout << "Enter groupId: ";
            std::cin >> receiverId;
            std::cout << "Enter message: ";
            getline(std::cin >> std::ws, message);
            //messageController.sendMessageToGroup(user.getUsername(), user.getSocketFd(), receiverId, message);
        }

    }
    return 0;
}