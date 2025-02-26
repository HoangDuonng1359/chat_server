#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include "../model/IService.h"
#include <vector>
#include <thread>
#include <memory>

class ServiceManager {
private:
    std::vector<std::unique_ptr<std::thread>> threads;
    std::vector<IService*> services;

public:
    void addService(IService* service);
    void startAll();
    void stopAll();
};

#endif
