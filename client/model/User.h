#ifndef USER_H
#define USER_H

#include<string>

class User {
    private:
        std::string id;
        std::string username;
        std::string password;
        std::string email;
        std::string phone;
        std::string address;
        std::string role;
        int socket_fd;
    public:
        User();
        User(std::string id, std::string username, std::string password, std::string email, std::string phone, std::string address, std::string role);
        User(std::string id, int socket_fd);
        std::string getUsername();
        std::string getPassword();
        std::string getEmail();
        std::string getPhone();
        std::string getAddress();
        std::string getRole();
        int getSocketFd();
        void setSocketFd(int socket_fd);
        void setUsername(std::string username);
        void setPassword(std::string password);
        void setEmail(std::string email);
        void setPhone(std::string phone);
        void setAddress(std::string address);
        void setRole(std::string role);
        void setId(std::string id);
        std::string getId();
}; 

#endif