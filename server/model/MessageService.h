#ifndef MESSAGE_SERVICE_H
#define MESSAGE_SERVICE_H

#define TOCLIENT "toClient"
#define TOGROUP "toGroup"
#define CREATEGROUP "createGroup"
#define DELETEGROUP "deleteGroup"
#define ADDMEMBER "addMember"
#define REMOVEMEMBER "removeMember"
#define LEAVEGROUP "leaveGroup"
#define LISTGROUP "listGroup"
#define LISTMEMBER "listMember"
#define LISTGROUPMEMBER "listGroupMember"
#define LISTALLGROUP "listAllGroup"
#define LISTALLMEMBER "listAllMember"
#define LISTALLGROUPMEMBER "listAllGroupMember"


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
    static std::string getValueByKey(const std::string& message, const std::string& key);
    
};

#endif
