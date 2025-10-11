#ifndef Order_hpp
#define Order_hpp

#include<string>
#include<vector>
#include "Product.hpp"

enum class OrderStatus{
    Pending, Delivering, Cancelled
};

inline std::string to_string(OrderStatus s){
    switch(s){
        case OrderStatus::Pending: return "Pending";
        case OrderStatus::Delivering: return "Delivering";
        case OrderStatus::Cancelled: return "Cancelled";
    }
    return "Unknown Status"; 
}


class Order{
    private:
        std::string customername;
        std::vector<Product> OrderItems;
        double total;
        OrderStatus status;
    public:
        Order(const std::string& customername,const std::vector<Product>& items,double total,OrderStatus status=OrderStatus::Pending);
        const std::string getCustomerName() const;
        void setStatus(OrderStatus s);
        OrderStatus getOrderStatus() const;
        const std::vector<Product>& getOrderItems() const;
        double gettotal() const;
};



#endif 