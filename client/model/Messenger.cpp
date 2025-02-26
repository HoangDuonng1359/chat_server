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
