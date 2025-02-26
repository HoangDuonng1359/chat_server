#ifndef CONNECTION_SERVICE_H
#define CONNECTION_SERVICE_H

#include "IService.h"
#include <map>
#include <string>
#include <netinet/in.h>
#include <atomic>
#include "GroupChat.h"
#include  "../controller/ClientManager.h"

class ConnectionService : public IService {
private:
    int serverSocket;
    ClientManager& clientManager;
    std::atomic<bool> running;
public:
    ConnectionService(int port);
    ~ConnectionService();

    void start() override;  // Bắt đầu lắng nghe kết nối
    void stop() override;   // Đóng kết nối
    void acceptConnection();
    void removeClient(std::string username);
    void addClient(int clientSocket, const std::string& username);
    void handleClient(std::string username); // handle each client
};

#endif
