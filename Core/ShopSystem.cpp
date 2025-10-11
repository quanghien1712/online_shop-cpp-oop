#include "ShopSystem.hpp"
#include "Entities/Admin.hpp"

ShopSystem::ShopSystem():
    productManager(std::make_unique<ProductManager>()),
    orderManager(std::make_unique<OrderManager>()),
    userManager(std::make_unique<UserManager>())
{
    initializeDefaultAdmin();
    productManager->loadProductsFromFile("ProductList.txt");
    orderManager->loadOrderFromFile("OrderList.txt");
}

void ShopSystem::initializeDefaultAdmin(){
    userManager->addUser(std::make_unique<Admin>("Admin","123"));
}

ProductManager& ShopSystem::getProductManager(){
    return *productManager;
}

OrderManager& ShopSystem::getOrderManager(){
    return *orderManager;
}

UserManager& ShopSystem::getUserManager(){
    return *userManager;
}

ShopSystem::~ShopSystem(){
    productManager->saveProductsToFile("ProductList.txt");
    orderManager->saveOrderToFile("OrderList.txt");
}
