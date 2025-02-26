#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <map>
#include <memory>
#include <string>
#include "../model/Client.h"


class ClientManager {
private:
    std::map<std::string, Client> clients; 

    // Ẩn constructor, copy constructor và operator=
    ClientManager() {} 
    ClientManager(const ClientManager&) = delete;
    ClientManager& operator=(const ClientManager&) = delete;

public:
    static ClientManager& getInstance() ;
    void addClient(std::string id, Client client);
    void removeClient(std::string id);
    Client getClient(std::string id);
    bool isClientExist(std::string id);
    std::map<std::string, Client> getClients();
    void clearClients();
};

#endif // CLIENT_MANAGER_H
