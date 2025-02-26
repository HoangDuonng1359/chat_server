#ifndef CONNECTION_CONTROLLER_H
#define CONNECTION_CONTROLLER_H


#include "../model/User.h"
#include "../model/Connection.h"

class ConnectionController
{
private:
    User user;
    Connection connection;
public:
    ConnectionController(User user, Connection connection);
    ~ConnectionController();
    int connectToServer();
    void disconnect();
};


#endif