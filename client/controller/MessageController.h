#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include "../model/User.h"
#include "../model/Messenger.h"
#include <iostream>
#include <string>


class MessageController {
    public:
        MessageController();
        void sendMessage(std::string sender_id, int socketFd, std::string receiver_id , std::string content , std::string type);
        void receiveMessage(int socketFd);
        void startReceivingMessage(int socketFd);
};


#endif // MESSAGECONTROLLER_H