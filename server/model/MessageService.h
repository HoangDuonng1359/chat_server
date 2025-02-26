#ifndef MESSAGE_SERVICE_H
#define MESSAGE_SERVICE_H

#define TOCLIENT "toClient"
#define TOGROUP "toGroup"

#include "IService.h"
#include <string>
#include <map>
#include "GroupChat.h"


class MessageService : public IService {
public:
    void start() override {}  
    void stop() override {}  
    int sendMessage(std::string msg);
    int sendToClient(std::string msg);
    int sendToGroup(std::string msg);
    std::string getReceiverIdByMessage(std::string message);
    std::string getContentByMessage(std::string message);
    std::string getCreatedAtByMessage(std::string message);
    std::string getSenderIdByMessage(std::string message);
    std::string getIdByMessage(std::string message);
    std::string getTypeByMessage(std::string message);
    std::string getValueByKey(const std::string& message, const std::string& key);
    
};

#endif
