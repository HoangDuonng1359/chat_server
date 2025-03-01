#include "GroupManager.h"
#include "../model/MessageService.h"
#include "ClientManager.h"

GroupManager& GroupManager::getInstance()
{
    static GroupManager instance;
    return instance;
}

void GroupManager::createGroup(std::string groupName, int groupID, Client& creator)
{
    GroupChat group(groupID, std::make_shared<Client>(creator), groupName);
    groupMap[groupID] = group;
}

void GroupManager::deleteGroup(int groupID)
{
    groupMap.erase(groupID);
}

void GroupManager::addGroup(int groupID, GroupChat group)
{
    groupMap[groupID] = group;
}

GroupChat GroupManager::getGroup(int groupID)
{
    return groupMap[groupID];
}

bool GroupManager::isGroupExist(int groupID)
{
    return groupMap.find(groupID) != groupMap.end();
}

std::map<int, GroupChat> GroupManager::getGroups()
{
    return groupMap;
}

GroupChat GroupManager::getGroupByName(std::string groupName)
{
    for (auto& group : groupMap) {
        if (group.second.getName() == groupName) {
            return group.second;
        }
    }
    return GroupChat();
}

void GroupManager::clearGroups()
{
    groupMap.clear();
}

void GroupManager::createGroup(std::string msg)
{
    std::string groupName = MessageService::getValueByKey(msg, "Group Name: ");
    std::string creatorID = MessageService::getValueByKey(msg, "Creator ID: ");
    Client creator = ClientManager::getInstance().getClient(creatorID);
    createGroup(groupName, groupMap.size(), creator);
}

void GroupManager::deleteGroup(std::string msg)
{
    std::string grName = MessageService::getValueByKey(msg, "Group Name: ");
    int groupID = getGroupByName(grName).getId();
    deleteGroup(groupID);
}

void GroupManager::addMemberToGroup(std::string msg)
{
    std::string grName = MessageService::getValueByKey(msg, "Group Name: ");
    int groupID = getGroupByName(grName).getId();
    std::string memberID = MessageService::getValueByKey(msg, "Member ID: ");
    groupMap[groupID].addMember(ClientManager::getInstance().getClient(memberID));
}

void GroupManager::removeMemberFromGroup(std::string msg)
{
    std::string grName = MessageService::getValueByKey(msg, "Group Name: ");
    int groupID = getGroupByName(grName).getId();
    std::string memberID = MessageService::getValueByKey(msg, "Member ID: ");
    groupMap[groupID].removeMember(memberID);
}

void GroupManager::leaveGroup(std::string msg)
{
    std::string grName = MessageService::getValueByKey(msg, "Group Name: ");
    int groupID = getGroupByName(grName).getId();
    std::string memberID = MessageService::getValueByKey(msg, "Member ID: ");
    groupMap[groupID].removeMember(memberID);
}

// int GroupManager::listGroup(std::string msg)
// {
//     std::string memberID = MessageService::getValueByKey(msg, "Member ID");
//     std::string response = "List Group\n";
//     for (auto& group : groupMap) {
//         if (group.second.isMember(memberID)) {
//             response += "Group ID: " + std::to_string(group.second.getId()) + " Group Name: " + group.second.getName() + "\n";
//         }
//     }
//     return MessageService::sendToClient(response);
// }

// int GroupManager::listMember(std::string msg)
// {
//     int groupID = std::stoi(MessageService::getValueByKey(msg, "Group ID"));
//     std::string response = "List Member\n";
//     for (auto& member : groupMap[groupID].getMembers()) {
//         response += member.getUsername() + "\n";
//     }
//     return MessageService::sendToClient(response);
// }

// int GroupManager::listGroupMember(std::string msg)
// {
//     std::string response = "List Group Member\n";
//     for (auto& group : groupMap) {
//         response += group.second.getName() + "\n";
//         for (auto& member : group.second.getMembers()) {
//             response += member.getUsername() + "\n";
//         }
//     }
//     return MessageService::sendToClient(response);
// }

// int GroupManager::listAllGroup()
// {
//     std::string response = "List All Group\n";
//     for (auto& group : groupMap) {
//         response += group.second.toString() + "\n";
//     }
//     return MessageService::sendToClient(response);
// }

// int GroupManager::listAllMember()
// {
//     std::string response = "List All Member\n";
//     for (auto& group : groupMap) {
//         response += group.second.getName() + "\n";
//         for (auto& member : group.second.getMembers()) {
//             response += member.getUsername() + "\n";
//         }
//     }
//     return MessageService::sendToClient(response);
// }

// int GroupManager::listAllGroupMember()
// {
//     std::string response = "List All Group Member\n";
//     for (auto& group : groupMap) {
//         response += group.second.getName() + "\n";
//         for (auto& member : group.second.getMembers()) {
//             response += member.getUsername() + "\n";
//         }
//     }
//     return MessageService::sendToClient(response);
// }

// int GroupManager::listMemberByGroup(std::string msg)
// {
//     int groupID = std::stoi(MessageService::getValueByKey(msg, "Group ID"));
//     std::string response = "List Member\n";
//     for (auto& member : groupMap[groupID].getMembers()) {
//         response += member.getUsername() + "\n";
//     }
//     return MessageService::sendToClient(response);
// }

// int GroupManager::listGroupByMember(std::string msg)
// {
//     std::string memberID = MessageService::getValueByKey(msg, "Member ID");
//     std::string response = "List Group\n";
//     for (auto& group : groupMap) {
//         if (group.second.isMember(memberID)) {
//             response += group.second.toString() + "\n";
//         }
//     }
//     return MessageService::sendToClient(response);
// }

