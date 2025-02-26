#ifndef ISERVICE_H
#define ISERVICE_H

class IService {
public:
    virtual void start() = 0; // Khởi động service
    virtual void stop() = 0;  // Dừng service
    virtual ~IService() {}    // Đảm bảo hủy đúng cách
};

#endif
