#include "Admin.hpp"
#include "Manager/ProductManager.hpp"
#include "Core/ShopSystem.hpp"
#include "UI/AdminUIHandler.hpp"

Admin::Admin(const std::string& username,const std::string& password):
    User(username,password,"Admin")
{}

void Admin::menu(ShopSystem& store){
    AdminUIHandler ui;
    ui.handleAdminMenu(store);
}

