#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "User.hpp"
#include "Cart.hpp"
#include "Product.hpp"
#include "Order.hpp"
#include<vector>

class ProductManager;
class OrderManager;
class ShopSystem;

class Customer:public User{
    private:
        Cart CustomerCart;
        std::vector<Order*> orderHistory;
    public:
        Customer(const std::string& username,const std::string& password);
        void checkout(OrderManager& orderManager,ProductManager& productManager);
        Cart* getCart() ;
        std::vector<Order*>& getOrderHistory() ;
        void setOrderHistory(const std::vector<Order*>& CustomerOrders);
        void menu(ShopSystem& store)override;
};


#endif 