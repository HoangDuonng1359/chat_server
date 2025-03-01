#include "model/User.h"
#include "controller/ConnectionController.h"
#include "controller/MessageController.h"
#include<iostream>
#include <string>
#include "model/Messenger.h"
#include "ctime"
#include "iomanip"
#include <sstream>
int main() {
    User user;
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;
    user.setUsername(username);
    Connection connection("127.0.0.1", 8081);
    ConnectionController connectionController(user, connection);
    int socket_fd = connectionController.connectToServer();
    user.setSocketFd(socket_fd);
    
    MessageController messageController;
    messageController.startReceivingMessage(user.getSocketFd());
    
    bool isSending = true;
    while(isSending){
        std::string message;
        std::string receiverId;
        std::string memberId;

        int choiceType;
        std::cout << "1. Send to user\n2. Send to group\n3. Create group\n4. Delete group\n5. Add member\n6. Remove member\n7. Leave group\n8. List group\n9. List member\n10. List group member\n11. List all group\n12. List all member\n13. List all group member\n";
        std::cout<<"14. Exit\n Enter choice: ";
        std::cin >> choiceType;
        Messenger msg;
        std::time_t now;
        std::tm* localTime;
        std::ostringstream oss;

        switch (choiceType)
        {
        case 1:
            std::cout << "Enter receiverId: ";
            std::cin >> receiverId;
            std::cout << "Enter message: ";
            getline(std::cin >> std::ws, message);
            msg.setContent(message);
            msg.setSenderId(user.getUsername());
            msg.setType(TOCLIENT);
            msg.setReceiverId(receiverId);

            now = time(0);
            localTime = std::localtime(&now); 

            oss.str("");
            oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
            msg.setCreatedAt(oss.str());

            messageController.sendMessage(user.getSocketFd(), msg.toString());
            break;
        case 2:
            std::cout << "Enter group name: ";
            std::cin >> receiverId;
            std::cout << "Enter message: ";
            getline(std::cin >> std::ws, message);

            msg.setContent(message);
            msg.setSenderId(user.getUsername());
            msg.setType(TOGROUP);
            msg.setReceiverId(receiverId);

            now = time(0);
            localTime = std::localtime(&now); 

            oss.str("");
            oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
            msg.setCreatedAt(oss.str());
            messageController.sendMessage(user.getSocketFd() , msg.toString());
            break;
        case 3:
            std::cout << "Enter group name: ";
            getline(std::cin >> std::ws, message);
            messageController.sendMessage(user.getSocketFd() , Messenger::createMsgCreateGroup(message,user.getUsername()));
            break;
        case 4: 
            std::cout << "Enter group name: ";
            std::cin >> receiverId;
            messageController.sendMessage(user.getSocketFd(), Messenger::createMsgDeleteGroup(receiverId));
            break;
        case 5:
            std::cout << "Enter group name: ";
            std::cin >> receiverId;
            std::cout << "Enter memberId: ";
            std::cin >> memberId;
            messageController.sendMessage(user.getSocketFd(), Messenger::createMsgAddMember(receiverId,memberId));
            break;
        case 6:
            std::cout << "Enter group name: ";
            std::cin >> receiverId;
            std::cout << "Enter memberId: ";
            std::cin >> memberId;
            messageController.sendMessage(user.getSocketFd(), Messenger::createMsgRemoveMember(receiverId,memberId));
            break;
        case 7:
            std::cout << "Enter group name: ";
            std::cin >> receiverId;
            messageController.sendMessage(user.getSocketFd(), Messenger::createMsgLeaveGroup(receiverId, user.getUsername()));
            break;
        // case 8:
        //     messageController.sendMessage(user.getUsername(), user.getSocketFd(), receiverId, message, LISTGROUP);
        //     break;
        // case 9:
        //     std::cout << "Enter groupId: ";
        //     std::cin >> receiverId;
        //     messageController.sendMessage(user.getUsername(), user.getSocketFd(), receiverId, message, LISTMEMBER);
        //     break;
        // case 10:
        //     std::cout << "Enter groupId: ";
        //     std::cin >> receiverId;
        //     messageController.sendMessage(user.getUsername(), user.getSocketFd(), receiverId, message, LISTGROUPMEMBER);
        //     break;
        // case 11:
        //     messageController.sendMessage(user.getUsername(), user.getSocketFd(), receiverId, message, LISTALLGROUP);
        //     break;
        // case 12:
        //     messageController.sendMessage(user.getUsername(), user.getSocketFd(), receiverId, message, LISTALLMEMBER);
        //     break;
        // case 13:    
        //     messageController.sendMessage(user.getUsername(), user.getSocketFd(), receiverId, message, LISTALLGROUPMEMBER);
        //     break;
        case 14:
            isSending = false;
            break;
        default:
            isSending = false;
            break;
        }
        

    }
    return 0;
}