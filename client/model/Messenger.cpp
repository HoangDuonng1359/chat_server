#include "Messenger.h"
#include <iostream>




Messenger::Messenger() {
    this->id = "";
    this->type = "";
    this->sender_id = "";
    this->receiver_id = "";
    this->content = "";
    this->created_at = "";
}

Messenger::Messenger(std::string id, std::string sender_id, std::string receiver_id, std::string content, std::string created_at) {
    this->id = id;
    this->sender_id = sender_id;
    this->receiver_id = receiver_id;
    this->content = content;
    this->created_at = created_at;
    this->type = TOCLIENT;
}

std::string Messenger::getType() {
    return this->type;
}

void Messenger::setType(std::string type) {
    this->type = type;
}
std::string Messenger::getId()  {
    return this->id;
}

std::string Messenger::getSenderId()  {
    return this->sender_id;
}

std::string Messenger::getReceiverId()  {
    return this->receiver_id;
}

std::string Messenger::getContent()  {
    return this->content;
}

std::string Messenger::getCreatedAt()  {
    return this->created_at;
}

void Messenger::setId(std::string id) {
    this->id = id;
}

void Messenger::setSenderId(std::string sender_id) {
    this->sender_id = sender_id;
}

void Messenger::setReceiverId(std::string receiver_id) {
    this->receiver_id = receiver_id;
}

void Messenger::setContent(std::string content) {
    this->content = content;
}

void Messenger::setCreatedAt(std::string created_at) {
    this->created_at = created_at;
}

std::string Messenger::toString() { 
    return "-----------msg box-------\nID: " + this->id + "\n" + "Type: " + this->type + "\n" + "Sender: " + this->sender_id + "\n" + "Receiver: " + this->receiver_id + "\n" + "Content: " + this->content + "\n" + "Created At: " + this->created_at + "\n" + "-------------------\n" ;
}

std::string Messenger::createMsgCreateGroup(std::string group_name, std::string creator_id) {
    return std::string("Type: ") + CREATEGROUP + "\nGroup Name: " + group_name + "\nCreator ID: " + creator_id + "\n";
}

std::string Messenger::createMsgDeleteGroup(std::string group_name) {
    return std::string("Type: ") + DELETEGROUP + "\nGroup Name: " + group_name + "\n";
}

std::string Messenger::createMsgAddMember(std::string group_name, std::string member_id) {
    return std::string("Type: ") + ADDMEMBER + "\nGroup Name: " + group_name + "\nMember ID: " + member_id + "\n";
}

std::string Messenger::createMsgRemoveMember(std::string group_name, std::string member_id) {
    return std::string("Type: ") + REMOVEMEMBER + "\nGroup Name: " + group_name + "\nMember ID: " + member_id + "\n";
}

std::string Messenger::createMsgLeaveGroup(std::string group_name, std::string user_id) {
    return std::string("Type: ") + LEAVEGROUP + "\nGroup Name: " + group_name + "\nClient ID:" + user_id;
}

std::string Messenger::createMsgListAllGroup() {
    return std::string("Type: ") + LISTALLGROUP + "\n";
}

std::string Messenger::createMsgListAllMember() {
    return std::string("Type: ") + LISTALLMEMBER + "\n";
}

std::string Messenger::createMsgListAllGroupMember() {
    return std::string("Type: ") + LISTALLGROUPMEMBER + "\n";
}

std::string Messenger::createMsgListMember(std::string group_name) {
    return std::string("Type: ") + LISTMEMBER + "\nGroup Name: " + group_name + "\n";
}

std::string Messenger::createMsgListGroup(std::string member_id) {
    return std::string("Type: ") + LISTGROUP + "\nGroup Name:: " + member_id + "\n";
}