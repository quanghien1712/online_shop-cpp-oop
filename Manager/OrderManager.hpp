#ifndef ORDER_MANAGER_HPP
#define ORDER_MANAGER_HPP

#include "Entities/Order.hpp"
#include<vector>
#include<memory>
#include<string>
#include "Entities/Product.hpp"

class OrderManager{
    private:
        std::vector<std::unique_ptr<Order>> orderList;
    public:
        Order* addOrder(const std::string& username,std::vector<Product>& items,double total,OrderStatus status=OrderStatus::Pending);
        std::vector<Order*> findOrderbyName(const std::string& customername);
        void acceptOrder(int OrderId);
        void cancelOrder(int OrderId);
        std::vector<Order*> getorderList();
        void loadOrderFromFile(const std::string& filename);
        void saveOrderToFile(const std::string& filename);
};

#endif