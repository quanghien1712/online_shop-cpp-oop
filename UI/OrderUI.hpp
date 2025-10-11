#ifndef ORDERUI_HPP
#define ORDERUI_HPP

#include "Entities/Order.hpp"
#include "Entities/Product.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include "Core/Exception.hpp"

class OrderUI{
    public:
        static void displayOrderDetail(Order* order){
            const std::vector<Product>& items=order->getOrderItems();
            for(int i=0;i<(int)items.size();++i){
                std::cout<<"x"<<items[i].getQuantity()<<" "<<items[i].getName()<<std::endl;
            }
            std::cout<<"Status: "<<to_string(order->getOrderStatus())<<std::endl;
            std::cout<<"Total: "<<std::fixed<<std::setprecision(2)<<order->gettotal()<<std::endl;
        }
        static void displayOrderList(const std::vector<Order*>& orderList){
            std::cout<<"=====OrderHistory====="<<std::endl;
            std::cout<<std::endl;
            if((int)orderList.size()==0){
                throw InvalidOrderException("Order list is empty");
            }
            for(int i=0;i<(int)orderList.size();++i){
                std::cout<<i<<". Customer: "<<orderList[i]->getCustomerName()<<std::endl;
                displayOrderDetail(orderList[i]);
            }
        }
};

#endif