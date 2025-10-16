#include "Order.hpp"



Order::Order(const std::string& customername, const std::vector<Product>& items,double total,OrderStatus status):
    customername(customername),OrderItems(items),total(total),status(status)
{}

const std::string& Order::getCustomerName()const{
    return customername;
}

const std::vector<Product>& Order::getOrderItems() const{
    return OrderItems;
}


void Order::setStatus(OrderStatus s){
    status=s;
}

OrderStatus Order::getOrderStatus() const{
    return status;
}

double Order::gettotal() const{
    return total;
}

