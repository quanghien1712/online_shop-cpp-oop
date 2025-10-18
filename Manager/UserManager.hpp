#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include "Entities/User.hpp"
#include<vector>
#include<memory>
class OrderManager;

class UserManager{
    private:
        std::vector<std::unique_ptr<User>> userList;
    public:
        void addUser(std::unique_ptr<User> user);
        User* findUser(const std::string& username);
        void loadUserFromFile(const std::string& filename);
        void saveUserToFile(const std::string& filename);
        void linkOrdertoCustomer(OrderManager& orderManager);
};

#endif