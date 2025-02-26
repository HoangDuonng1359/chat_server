#include "User.h"
#include <iostream>

User::User() {
    this->id = ""; // tạm thời chưa dùng cái này
    this->username = "";
    this->password = "";
    this->email = "";
    this->phone = "";
    this->address = "";
    this->role = "";
    this->socket_fd = -1;
}

User::User(std::string id, std::string username, std::string password, std::string email, std::string phone, std::string address, std::string role) {
    this->id = id;
    this->username = username;
    this->password = password;
    this->email = email;
    this->phone = phone;
    this->address = address;
    this->role = role;
    this->socket_fd = -1;
}

User::User(std::string id, int socket_fd) {
    this->id = id;
    this->username = "";
    this->password = "";
    this->email = "";
    this->phone = "";
    this->address = "";
    this->role = "";
    this->socket_fd = socket_fd;
}

std::string User::getUsername() {
    return this->username;
}

std::string User::getPassword() {
    return this->password;
}

std::string User::getEmail() {
    return this->email;
}

std::string User::getPhone() {
    return this->phone;
}

std::string User::getAddress() {
    return this->address;
}

std::string User::getRole() {
    return this->role;
}

void User::setUsername(std::string username) {
    this->username = username;
}

void User::setPassword(std::string password) {
    this->password = password;
}

void User::setEmail(std::string email) {
    this->email = email;
}

void User::setPhone(std::string phone) {
    this->phone = phone;
}

void User::setAddress(std::string address) {
    this->address = address;
}

void User::setRole(std::string role) {
    this->role = role;
}

void User::setId(std::string id) {
    this->id = id;
}

std::string User::getId() {
    return this->id;
}

int User::getSocketFd() {
    return this->socket_fd;
}

void User::setSocketFd(int socket_fd) {
    this->socket_fd = socket_fd;
}

