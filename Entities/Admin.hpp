#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "User.hpp"

class ShopSystem;


class Admin:public User{
    public:
        Admin(const std::string& username,const std::string& password);
        void menu(ShopSystem& store) override;
        
};

#endif  