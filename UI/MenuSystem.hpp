#ifndef MENUSYSTEM_HPP
#define MENUSYSTEM_HPP


class ShopSystem;
class UserManager;

class MenuSystem{
    private:
        void displayMainMenu();
        void handleLogin(ShopSystem& store);
        void handleRegister(UserManager& userManager);
    public:
        void handleMainMenu(ShopSystem& store);
        
};

#endif