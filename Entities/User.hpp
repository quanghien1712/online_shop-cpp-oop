#ifndef User_HPP
#define User_HPP

#include<string>

class ShopSystem;

class User{
    protected:
        std::string username,password,role;
    public:
        User(const std::string& username,const std::string& password,const std::string& role):
            username(username),password(password),role(role)
        {}
        bool authenticatePassword(const std::string& inputPassword){
            return password==inputPassword;
        }
        const std::string& getUsername() const{
            return username;
        }
        const std::string& getpassword() const{
            return password;
        }
        const std::string& getRole() const{
            return role;
        }
        virtual void menu(ShopSystem& store)=0;
        virtual ~User()=default;
}; 



#endif 