#include "OrderManager.hpp"
#include "Core/Exception.hpp"
#include<fstream>
#include<sstream>

Order* OrderManager::addOrder(const std::string& username,std::vector<Product>& items,double total,OrderStatus status){
    std::unique_ptr<Order> newOrder= std::make_unique<Order>(username,items,total,status);
    Order* orderPtr=newOrder.get();
    orderList.push_back(std::move(newOrder));
    return orderPtr;
}

std::vector<Order*> OrderManager::findOrderbyName(const std::string& customername){
    std::vector<Order*> CustomerOrder;
    for(auto &x:orderList){
        if(x->getCustomerName()==customername){
            CustomerOrder.push_back(x.get());
        }
    }
    return CustomerOrder;
}

void OrderManager::acceptOrder(int OrderId){
    auto& order=orderList[OrderId];
    if(order->getOrderStatus()==OrderStatus::Cancelled){
        throw InvalidOrderException("Cannot accept order that has been cancelled");
    }
    order->setStatus(OrderStatus::Delivering);
}

void OrderManager::cancelOrder(int OrderId){
    auto &order=orderList[OrderId];
    if(order->getOrderStatus()==OrderStatus::Delivering){
        throw InvalidOrderException("This order is being delivered");
    }
    order->setStatus(OrderStatus::Cancelled);
}

std::vector<Order*> OrderManager::getorderList(){
    std::vector<Order*> OrderPtrList;
    for(int i=0;i<(int)orderList.size();++i){
        OrderPtrList.push_back(orderList[i].get());
    }
    return OrderPtrList;
}

void OrderManager::saveOrderToFile(const std::string& filename){
    std::ofstream output(filename);
    if(!output) return;
    for(auto& order:orderList){
        const std::vector<Product>& items=order->getOrderItems();
        output<<order->getCustomerName()<<","<<order->gettotal()<<" "<<(int)order->getOrderStatus()<<" "<<items.size()<<'\n';
        for(const auto& product:items){
            output<<product.getName()<<","<<product.getPrice()<<" "<<product.getQuantity()<<'\n';
        }
    }
    output.close();
}


void OrderManager::loadOrderFromFile(const std::string& filename){
    std::ifstream input(filename);
    if(!input) return;
    std::string line;
    while(std::getline(input,line)){
        std::stringstream ss(line);
        std::string customerName;std::getline(ss,customerName,',');
        double total;ss>>total;
        int statusInt;ss>>statusInt;
        OrderStatus status=static_cast<OrderStatus> (statusInt);
        int itemSize;ss>>itemSize;
        std::vector<Product> items;
        for(int i=1;i<=itemSize;++i){
            std::getline(input,line);
            std::stringstream ss(line);
            std::string productname;std::getline(ss,productname,',');
            double price;ss>>price;
            int quantity;ss>>quantity;
            items.emplace_back(productname,quantity,price);
        }
        addOrder(customerName,items,total,status);
    }
    input.close();
}





