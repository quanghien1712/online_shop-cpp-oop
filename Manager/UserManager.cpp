#include "UserManager.hpp"
#include "Entities/Customer.hpp"
#include "Entities/Admin.hpp"
#include<fstream>
#include<sstream>

void UserManager::addUser(std::unique_ptr<User> user){
    userList.push_back(std::move(user));
}

User* UserManager::findUser(const std::string& username){
    for(const std::unique_ptr<User>& user:userList){
        if(user->getUsername()==username){
            return user.get();
        }
    }
    return nullptr;
}

void UserManager::saveUserToFile(const std::string& filename){
    std::ofstream output(filename);
    if(!output) return;
    for(auto& user:userList){
        output<<user->getRole()<<" "<<user->getUsername()<<" "<<user->getpassword()<<'\n';
    }
    output.close();
}

void UserManager::loadUserFromFile(const std::string& filename){
    std::ifstream input(filename);
    if(!input) return;
    std::string line;
    while(std::getline(input,line)){
        std::stringstream ss(line);
        std::string role;ss>>role;
        std::string username;ss>>username;
        std::string password;ss>>password;
        if(role=="Customer") addUser(std::make_unique<Customer>(username,password)); 
    }
    input.close();
}