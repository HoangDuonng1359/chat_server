#include "GroupChat.h"
#include <iostream>

GroupChat::GroupChat(int id, std::shared_ptr<Client> admin, std::string name) {
    this->id = id;
    this->admin = admin;
    this->name = name;
    this->addMember(*admin);
}

GroupChat::GroupChat() {
    this->id = -1;
    this->admin = nullptr;
    this->name = "";
}

void GroupChat::setId(int id) {
    this->id = id;
}

void GroupChat::setName(const std::string& name) {
    this->name = name;
}

void GroupChat::setAdmin(std::shared_ptr<Client> admin) {
    this->admin = admin;
}

void GroupChat::setCreatedAt(const std::string& created_at) {
    this->created_at = created_at;
}

void GroupChat::setUpdatedAt(const std::string& updated_at) {
    this->updated_at = updated_at;
}

int GroupChat::getId() const {
    return this->id;
}

std::string GroupChat::getName() const {
    return this->name;
}

std::string  GroupChat::getAdminId() const {
    return this->admin->getUsername();
}

std::string GroupChat::getCreatedAt() const {
    return this->created_at;
}

std::string GroupChat::getUpdatedAt() const {
    return this->updated_at;
}

void GroupChat::addMember(const Client& member) {
    this->members.push_back(member);
}

const std::vector<Client>& GroupChat::getMembers() const {
    return this->members;
}

void GroupChat::setMembers(const std::vector<Client>& members) {
    this->members = members;
}

void GroupChat::removeMember(std::string member_id) {
    int n = this->members.size();
    for (int i = 0; i < n ; i++) {
        if (this->members[i].getUsername() == member_id) {
            this->members.erase(this->members.begin() + i);
            return;
        }
    }
}

bool GroupChat::isMember(std::string member_id) {
    int n = this->members.size();
    for (int i = 0; i < n; i++) {
        if (this->members[i].getUsername() == member_id) {
            return true;
        }
    }
    return false;
}

void GroupChat::clearMembers() {
    this->members.clear();
}

