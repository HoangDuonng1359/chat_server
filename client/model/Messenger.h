#ifndef MESSENGER_H
#define MESSENGER_H
#define TOCLIENT "toClient"
#define TOGROUP "toGroup"

#include<string>

class Messenger {
    private:
        std::string id;
        std::string sender_id;
        std::string receiver_id;
        std::string content;
        std::string created_at;
        std::string type;
    public:
        Messenger();
        Messenger(std::string id, std::string sender_id, std::string receiver_id, std::string content, std::string created_at);
        std::string getId() ;
        std::string getSenderId() ;
        std::string getReceiverId()  ;
        std::string getContent() ;
        std::string getCreatedAt() ;
        void setId(std::string id) ;
        void setSenderId(std::string sender_id) ;
        void setReceiverId(std::string receiver_id) ;
        void setContent(std::string content) ;
        void setCreatedAt(std::string created_at) ;
        std::string toString();
        std::string getType();
        void setType(std::string type);
};

#endif