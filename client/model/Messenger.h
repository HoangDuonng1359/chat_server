#ifndef MESSENGER_H
#define MESSENGER_H
#define TOCLIENT "toClient"
#define TOGROUP "toGroup"
#define CREATEGROUP "createGroup"
#define DELETEGROUP "deleteGroup"
#define ADDMEMBER "addMember"
#define REMOVEMEMBER "removeMember"
#define LEAVEGROUP "leaveGroup"
#define LISTGROUP "listGroup"
#define LISTMEMBER "listMember"
#define LISTGROUPMEMBER "listGroupMember"
#define LISTALLGROUP "listAllGroup"
#define LISTALLMEMBER "listAllMember"
#define LISTALLGROUPMEMBER "listAllGroupMember"

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

        static std::string createMsgCreateGroup(std::string group_name, std::string creator_id);
        static std::string createMsgDeleteGroup(std::string group_name);
        static std::string createMsgAddMember(std::string group_name, std::string member_id);
        static std::string createMsgRemoveMember(std::string group_name, std::string member_id);
        static std::string createMsgLeaveGroup(std::string group_name, std::string user_id);
        static std::string createMsgListAllGroup();
        static std::string createMsgListAllMember();
        static std::string createMsgListAllGroupMember();
        static std::string createMsgListMember(std::string group_name);
        static std::string createMsgListGroup(std::string member_id);
};

#endif