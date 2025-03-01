#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

#include <map>
#include <string>
#include "../model/GroupChat.h"
#include "../model/Client.h"


class GroupManager
{
private:
    std::map<int, GroupChat> groupMap;
    GroupManager() {}
    GroupManager(const GroupManager&) = delete;
    GroupManager& operator=(const GroupManager&) = delete;
public:
    static GroupManager& getInstance();
    void createGroup(std::string groupName, int groupID, Client& creator);
    void createGroup(std::string msg);
    void deleteGroup(int groupID);
    void deleteGroup(std::string msg);
    void addGroup(int groupID, GroupChat group);
    void addMemberToGroup(std::string msg);
    void removeMemberFromGroup(std::string msg);
    GroupChat getGroup(int groupID);
    bool isGroupExist(int groupID);
    std::map<int, GroupChat> getGroups();
    void clearGroups();
    GroupChat getGroupByName(std::string groupName);
    void leaveGroup(std::string msg);
    int listGroup(std::string msg);
    int listMember(std::string msg);
    int listGroupMember(std::string msg);
    int listAllGroup();
    int listAllMember();
    int listAllGroupMember();
    int listMemberByGroup(std::string msg);
    int listGroupByMember(std::string msg);
};



#endif // GROUPMANAGER_H