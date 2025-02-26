#include "ServiceManager.h"
#include "../model/IService.h"

void ServiceManager::addService(IService* service) {
    services.push_back(service);
}

void ServiceManager::startAll() {
    for (auto service : services) {
        threads.push_back(std::unique_ptr<std::thread>(new std::thread([service]() {
            service->start();
        })));
    }
}

void ServiceManager::stopAll() {
    for (auto service : services) {
        service->stop();
    }
    for (auto& t : threads) {
        if (t->joinable()) {
            t->join();
        }
    }
}
