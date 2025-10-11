#ifndef ADMIN_UI__HANDLER_HPP
#define ADMIN_UI_HANDLER_HPP

class ShopSystem;
class ProductManager;
class OrderManager;

class AdminUIHandler{
    private:
        void displayAdminMenu();
        void displayProductManagementMenu();
        void displayOrderManagementMenu();
        void handleProductManagement(ProductManager& productManager);
        void handleOrderManagement(OrderManager& orderManager);
    public:
        void handleAdminMenu(ShopSystem& store);
};

#endif