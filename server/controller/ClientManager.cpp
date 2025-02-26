#include "ClientManager.h"
#include "../model/Client.h"
#include <string>

ClientManager::ClientManager() {
}

ClientManager& ClientManager::getInstance() {
    static ClientManager instance;
    return instance;
}

void ClientManager::addClient(std::string id, Client client) {
    this->clients[id] = client;
}

void ClientManager::removeClient(std::string id) {
    this->clients.erase(id);
}

Client ClientManager::getClient(std::string id) {
    return this->clients[id];
}

bool ClientManager::isClientExist(std::string id) {
    return this->clients.find(id) != this->clients.end();
}

std::map<std::string, Client> ClientManager::getClients() {
    return this->clients;
}