#ifndef GROUPCHAT_H
#define GROUPCHAT_H

#include <string>
#include <iostream>
#include <vector>
#include <memory> 
#include "Client.h"

class GroupChat {
private:
    int id;
    std::string name;
    std::shared_ptr<Client> admin;  // Dùng smart pointer thay vì tham chiếu
    std::string created_at;
    std::string updated_at;
    std::vector<Client> members;

public:
    GroupChat(int id, std::shared_ptr<Client> admin, std::string name);
    GroupChat();
    void setId(int id);
    void setName(const std::string& name);
    void setAdmin(std::shared_ptr<Client> admin);
    void setCreatedAt(const std::string& created_at);
    void setUpdatedAt(const std::string& updated_at);
    
    int getId() const;
    std::string getName() const;
    std::string getAdminId() const;
    std::string getCreatedAt() const;
    std::string getUpdatedAt() const;
    
    void addMember(const Client& member);
    const std::vector<Client>& getMembers() const;
    void setMembers(const std::vector<Client>& members);
    void removeMember(std::string member_id);
    bool isMember(std::string member_id);
    void clearMembers();
};

#endif // GROUPCHAT_H
