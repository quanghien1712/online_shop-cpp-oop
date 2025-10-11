#include "MenuSystem.hpp"
#include "Core/Util.hpp"
#include "Core/ShopSystem.hpp"
#include <iostream>
#include <string>
#include "Entities/User.hpp"
#include "Entities/Customer.hpp"
#include "Manager/UserManager.hpp"
#include <memory>

void MenuSystem::displayMainMenu(){
    Util::clearScreen();
    std::cout << "              ________________________________\n";
    std::cout << "             /                                \\\n";
    std::cout << "            /     HIEN'S  ONLINE  SHOP        \\\n";
    std::cout << "           /__________________________________\\\n";
    std::cout << "           |\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/|\n";
    std::cout << "           |/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\|\n";
    std::cout << "           |                                  |\n";
    std::cout << "           |   +--------------------------+   |\n";
    std::cout << "           |   |        1. Login          |   |\n";
    std::cout << "           |   |        2. Register       |   |\n";
    std::cout << "           |   |        3. Quit           |   |\n";
    std::cout << "           |   +--------------------------+   |\n";
    std::cout << "           |__________________________________|\n";
    std::cout << "          /                                    \\\n";
    std::cout << "         /______________________________________\\\n";
    std::cout << std::endl;
}

void MenuSystem::handleLogin(ShopSystem& store){
    Util::clearScreen();
    std::cout<<"======Login Menu====="<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Username: ";
    std::string username=Util::getValidatedStringInput();
    std::cout<<"Password: ";
    std::string password=Util::getValidatedStringInput();
    User* user=store.getUserManager().findUser(username);
    if(!user){
        std::cout<<"User not found"<<std::endl;
        Util::pressEntertoContinue();
        return;
    }
    if(!user->authenticatePassword(password)){
        std::cout<<"Incorrect password"<<std::endl;
        Util::pressEntertoContinue();
        return;
    }
    std::cout<<"Login Successfully"<<std::endl;
    Util::pressEntertoContinue();
    user->menu(store);
}

void MenuSystem::handleRegister(UserManager& userManager){
    Util::clearScreen();
    std::cout<<"=====Register Menu====="<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Username: ";
    std::string username=Util::getValidatedStringInput();
    std::cout<<"Password: ";
    std::string password=Util::getValidatedStringInput();
    if(userManager.findUser(username)!=nullptr){
        std::cout<<"Username's existed"<<std::endl;
        Util::pressEntertoContinue();
        return;
    }
    userManager.addUser(std::make_unique<Customer>(username,password));
    std::cout<<"Account has been created"<<std::endl;
    Util::pressEntertoContinue();
}


void MenuSystem::handleMainMenu(ShopSystem& store){
    while(1){
        Util::clearScreen();
        displayMainMenu();
        std::cout<<"Enter your choice: ";
        int choice=Util::getValidatedNumberInput<int>(0,3);
        switch(choice){
            case 1:
                handleLogin(store);
                break;
            case 2:
                handleRegister(store.getUserManager());
                break;
            case 3:
                return;
        }
    }
}


