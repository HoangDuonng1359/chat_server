#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include "../model/User.h"
#include "../model/Messenger.h"
#include <iostream>
#include <string>


class MessageController {
    public:
        MessageController();
        void sendMessage(int socketFd, std::string msg);
        void receiveMessage(int socketFd);
        void startReceivingMessage(int socketFd);
};


#endif // MESSAGECONTROLLER_H