# Chat Server - Installation & Usage Guide

## Introduction
This is a chat server-client system built with C++ using the TCP protocol. The system supports multiple clients connecting and chatting through the server.

## System Requirements
- **Ubuntu 22.04** or similar
- **g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0**
- **Make** to compile the source code

## Installation & Running Guide

### 1. Starting the Server
Open a new terminal and execute the following commands:
```sh
cd server
make
./main
```

### 2. Starting the Client
Open a new terminal and execute the following commands:
```sh
cd client
make
./main
```

## Common Issues & Solutions

### 1. Error: `make: command not found`
- Install Make using the following command:
  ```sh
  sudo apt update
  sudo apt install build-essential
  ```

### 2. Error: `g++: command not found`
- Install g++ using the following command:
  ```sh
  sudo apt update
  sudo apt install g++
  ```

### 3. Error: `Bind failed` when running the server
- The port may already be in use. Check and terminate the existing process:
  ```sh
  sudo netstat -tulnp | grep :<PORT>
  sudo kill -9 <PID>
  ```
  (Replace `<PORT>` with the port number and `<PID>` with the process ID.)

### 4. Error: `Connection refused` when running the client
- Ensure that the server is running before starting the client.
- Check the firewall settings:
  ```sh
  sudo ufw allow <PORT>
  ```

## Additional Information
- Each client will have a unique ID when connecting to the server.
- The system is designed for easy future upgrades.

