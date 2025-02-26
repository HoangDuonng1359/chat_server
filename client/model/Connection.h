#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include "User.h"

class Connection {
private:
    std::string serverIP;
    int serverPort;

public:
    Connection(const std::string& ip, int port);
    int connectToServer(User& user);  // Kết nối user tới server
    void disconnect(User& user);      // Ngắt kết nối
};

#endif