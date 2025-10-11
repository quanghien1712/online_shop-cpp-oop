#include "Customer.hpp"
#include "Manager/ProductManager.hpp"
#include "Manager/OrderManager.hpp"
#include "Core/ShopSystem.hpp"
#include "UI/CustomerUIHandler.hpp"


Customer::Customer(const std::string& username,const std::string& password)
: User(username,password,"Customer")
{}

Cart* Customer::getCart(){
    return &CustomerCart; 
}

void Customer::checkout(OrderManager& orderManager,ProductManager& productManager){
    std::vector<Product> items=CustomerCart.getItems();
    Order* newOrder=orderManager.addOrder(username,items,CustomerCart.gettotal());
    orderHistory.push_back(newOrder);
    for(int i=0;i<(int)items.size();++i){
        Product* product=productManager.findProductbyName(items[i].getName());
        product->reduceStock(items[i].getQuantity());
    }
    CustomerCart.clearCart();
}

void Customer::setOrderHistory(const std::vector<Order*>& CustomerOrder){
    orderHistory=CustomerOrder;
}


std::vector<Order*>& Customer::getOrderHistory(){
    return orderHistory;
}

void Customer::menu(ShopSystem& store) {
    CustomerUIHandler ui;
    ui.handleCustomerMenu(this,store);
}