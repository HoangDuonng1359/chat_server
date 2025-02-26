#include <iostream>
#include "MessageService.h"
#include <string>
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include "../controller/ClientManager.h"


int MessageService::sendMessage(std::string msg) {
    std::string type = getTypeByMessage(msg);
    if (type == TOCLIENT) {
        return sendToClient(msg);
    } else if (type == TOGROUP) {
        return sendToGroup(msg);
    }
    return -1;
}


int MessageService::sendToClient(std::string msg) {
    std::string receiverId = getReceiverIdByMessage(msg);
    int receiverSocket = ClientManager::getInstance().getClient(receiverId).getSocketFd();
    if (receiverSocket == -1) {
        return -1;
    }
    return send(receiverSocket, msg.c_str(), msg.length(), 0);
}

int MessageService::sendToGroup(std::string msg) {
    return -1;
}


std::string MessageService::getValueByKey(const std::string& message, const std::string& key) {
    size_t startPos = message.find(key);
    if (startPos == std::string::npos) return "";
    startPos += key.length();  
    
    size_t endPos = message.find("\n", startPos);
    if (endPos == std::string::npos) endPos = message.length();
    
    return message.substr(startPos, endPos - startPos);
}


std::string MessageService::getIdByMessage(std::string message) {
    return getValueByKey(message, "ID: ");
}

std::string MessageService::getTypeByMessage(std::string message) {
    return getValueByKey(message, "Type: ");
}

std::string MessageService::getReceiverIdByMessage(std::string message) {
    return getValueByKey(message, "Receiver: ");
}

std::string MessageService::getContentByMessage(std::string message) {
    return getValueByKey(message, "Content: ");
}

std::string MessageService::getCreatedAtByMessage(std::string message) {
    return getValueByKey(message, "Created At: ");
}

std::string MessageService::getSenderIdByMessage(std::string message) {
    return getValueByKey(message, "Sender: ");
}