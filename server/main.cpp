#include "controller/ServiceManager.h"
#include "model/ConnectionService.h"
#include "model/MessageService.h"
#include <thread>
#include <chrono>
#include <iostream>


int main() {
    ServiceManager manager;

    ConnectionService connection(8081);
    manager.addService(&connection);

    manager.startAll();

    manager.stopAll();

    return 0;
}
