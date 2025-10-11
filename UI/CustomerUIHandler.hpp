#ifndef CUSTOMER_UI_Handler_CPP
#define CUSTOMER_UI_Handler_CPP


#include "Entities/Product.hpp"
#include "Entities/Order.hpp"

class Customer;
class ShopSystem;
class ProductManager;
class OrderManager;

class CustomerUIHandler{
    private:
        void handleCart(Customer* customer,ShopSystem& store);
        void handleOrder(Customer* customer);
        void handleShoppingMenu(Customer* customer,ProductManager& productManager);
        void displayMyCart(const std::vector<Product>& items,double total);
        void displayMyOrder(const std::vector<Order*>& orderHistory);
        void displayShoppingOption();
        void displayCartOption();
        void displayCustomerMenu();
    public:
        void handleCustomerMenu(Customer* customer,ShopSystem& store);
        
};


#endif 