#include <iostream>
#include "MessageService.h"
#include <string>
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include "../controller/ClientManager.h"
#include "../controller/GroupManager.h"

int MessageService::sendMessage(std::string msg)
{
    std::string type = getTypeByMessage(msg);
    GroupManager &groupManager = GroupManager::getInstance();
    if (type == TOCLIENT)
    {
        return sendToClient(msg);
    }
    else if (type == TOGROUP)
    {
        return sendToGroup(msg);
    }
    else if (type == CREATEGROUP)
    {
        groupManager.createGroup(msg);
        return 1;
    }
    else if (type == DELETEGROUP)
    {
        groupManager.deleteGroup(msg);
        return 1;
    }
    else if (type == ADDMEMBER)
    {
        groupManager.addMemberToGroup(msg);
        return 1;
    }
    else if (type == REMOVEMEMBER)
    {
        groupManager.removeMemberFromGroup(msg);
        return 1;
        // } else if (type == LEAVEGROUP) {
        //     return leaveGroup(msg);
        // } else if (type == LISTGROUP) {
        //     return listGroup(msg);
        // } else if (type == LISTMEMBER) {
        //     return listMember(msg);
        // } else if (type == LISTGROUPMEMBER) {
        //     return listGroupMember(msg);
        // } else if (type == LISTALLGROUP) {
        //     return listAllGroup();
        // } else if (type == LISTALLMEMBER) {
        //     return listAllMember();
        // } else if (type == LISTALLGROUPMEMBER) {
        //     return listAllGroupMember();
        // }
        
    }
    return -1;
}

int MessageService::sendToClient(std::string msg)
{
    std::string receiverId = getReceiverIdByMessage(msg);
    int receiverSocket = ClientManager::getInstance().getClient(receiverId).getSocketFd();
    if (receiverSocket == -1)
    {
        return -1;
    }
    return send(receiverSocket, msg.c_str(), msg.length(), 0);
}

int MessageService::sendToGroup(std::string msg)
{
    std::string receiverName = getReceiverIdByMessage(msg);
    GroupChat group = GroupManager::getInstance().getGroupByName(receiverName);
    if (group.getId() == -1)
    {
        return -1;
    }
    std::vector<Client> members = group.getMembers();
    for (Client member : members)
    {
        int receiverSocket = member.getSocketFd();
        if (receiverSocket == -1)
        {
            continue;
        }
        send(receiverSocket, msg.c_str(), msg.length(), 0);
    }
    return 0;
}

std::string MessageService::getValueByKey(const std::string &message, const std::string &key)
{
    size_t startPos = message.find(key);
    if (startPos == std::string::npos)
        return "";
    startPos += key.length();

    size_t endPos = message.find("\n", startPos);
    if (endPos == std::string::npos)
        endPos = message.length();
    return message.substr(startPos, endPos - (startPos));
}

std::string MessageService::getIdByMessage(std::string message)
{
    return getValueByKey(message, "ID: ");
}

std::string MessageService::getTypeByMessage(std::string message)
{
    return getValueByKey(message, "Type: ");
}

std::string MessageService::getReceiverIdByMessage(std::string message)
{
    return getValueByKey(message, "Receiver: ");
}

std::string MessageService::getContentByMessage(std::string message)
{
    return getValueByKey(message, "Content: ");
}

std::string MessageService::getCreatedAtByMessage(std::string message)
{
    return getValueByKey(message, "Created At: ");
}

std::string MessageService::getSenderIdByMessage(std::string message)
{
    return getValueByKey(message, "Sender: ");
}