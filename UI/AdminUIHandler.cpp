#include "AdminUIHandler.hpp"
#include <iostream>
#include "Core/Util.hpp"
#include "Core/Exception.hpp"
#include "Manager/ProductManager.hpp"
#include "Manager/OrderManager.hpp"
#include "ProductUI.hpp"
#include <vector>
#include <string>
#include "Entities/Product.hpp"
#include "OrderUI.hpp"
#include "Entities/Order.hpp"
#include "Core/ShopSystem.hpp"

void AdminUIHandler::displayAdminMenu(){
    std::cout<<"=========== ADMIN MENU ==========="<<std::endl;
    std::cout<<"| 1. Manage Products              |"<<std::endl;
    std::cout<<"| 2. Add new product              |"<<std::endl;
    std::cout<<"| 3. Manage Orders                |"<<std::endl;
    std::cout<<"| 4. Logout                       |"<<std::endl;
    std::cout<<"==================================="<<std::endl;
    std::cout<<std::endl;
}

void AdminUIHandler::displayProductManagementMenu(){
    std::cout<<std::endl;
    std::cout<<"1. Add stock"<<std::endl;
    std::cout<<"2. Delete product"<<std::endl;
    std::cout<<"3. Change price"<<std::endl;
    std::cout<<"4. Back to Menu"<<std::endl;
    std::cout<<std::endl;
}

void AdminUIHandler::displayOrderManagementMenu(){
    std::cout<<std::endl;
    std::cout<<"1. Accept Order"<<std::endl;
    std::cout<<"2. Cancel Order"<<std::endl;
    std::cout<<"3. Back to Menu"<<std::endl;
    std::cout<<std::endl;
}

void AdminUIHandler::handleProductManagement(ProductManager& productManager){
    while(1){
        try{
            Util::clearScreen();
            std::vector<Product> productlist=productManager.getProductList();
            ProductUI::displayProductCatalogue(productlist);
            displayProductManagementMenu();
            std::cout<<"Enter your choice: ";
            int choice=Util::getValidatedNumberInput<int>(0,4);
            switch(choice){
                case 1:{
                    std::cout<<"Enter product's id to add: ";
                    int productId=Util::getValidatedNumberInput<int>(-1,(int)productlist.size()-1);
                    std::cout<<"Enter quantity to add: ";
                    int quantity=Util::getValidatedNumberInput<int>(0);
                    productManager.findProductbyId(productId)->addStock(quantity);
                    std::cout<<"Product's successfully added"<<std::endl;
                    break;
                }
                case 2:{
                    std::cout<<"Enter product's id to delete: ";
                    int productId=Util::getValidatedNumberInput<int>(-1,(int)productlist.size()-1);
                    std::cout<<"Enter quantity to delete: ";
                    int quantity=Util::getValidatedNumberInput<int>(0);
                    productManager.removeProduct(productId,quantity);
                    std::cout<<"Product's successfully removed"<<std::endl;
                    break;
                }
                case 3:{
                    std::cout<<"Enter product's id to change price: ";
                    int productId=Util::getValidatedNumberInput<int>(-1,(int)productlist.size()-1);
                    std::cout<<"Enter new price: ";
                    double newprice=Util::getValidatedNumberInput<double>(0);
                    productManager.findProductbyId(productId)->setPrice(newprice);
                    std::cout<<"Price has been changed"<<std::endl;
                    break;
                }
                case 4:
                    return;
            }
            Util::pressEntertoContinue();
        }
        catch(const InvalidProductException& e){
            std::cerr<<e.what()<<std::endl;
            Util::pressEntertoContinue();
            return;
        }
    }
}

void AdminUIHandler::handleOrderManagement(OrderManager& orderManager){
    while(1){
        try{
            Util::clearScreen();
            std::vector<Order*> orderList=orderManager.getorderList();
            OrderUI::displayOrderList(orderList);
            displayOrderManagementMenu();
            std::cout<<"Enter your choice: ";
            int choice=Util::getValidatedNumberInput<int>(0,3);
            switch(choice){
                case 1:{
                    try{
                        std::cout<<"Enter order's id to accept: ";
                        int orderId=Util::getValidatedNumberInput<int>(-1,(int)orderList.size()-1);
                        orderManager.acceptOrder(orderId);
                        std::cout<<"Order's accepted"<<std::endl;
                    }
                    catch(const InvalidOrderException& e){
                        std::cerr<<e.what()<<std::endl;
                    }
                    break;
                }
                case 2:{
                    try{
                        std::cout<<"Enter order's id to cancel: ";
                        int orderId=Util::getValidatedNumberInput<int>(-1,(int)orderList.size()-1);
                        orderManager.cancelOrder(orderId);
                        std::cout<<"Order's cancelled"<<std::endl;
                    }
                    catch(const InvalidOrderException& e){
                        std::cerr<<e.what()<<std::endl;
                    }
                    break;
                }
                case 3:
                    return;
            }
            Util::pressEntertoContinue();
        }
        catch(const InvalidOrderException& e){
            std::cerr<<e.what()<<std::endl;
            Util::pressEntertoContinue();
            return;
        }
    }
}

void AdminUIHandler::handleAdminMenu(ShopSystem& store){
    while(1){
        Util::clearScreen();
        displayAdminMenu();
        std::cout<<"Enter your choice: ";
        int choice=Util::getValidatedNumberInput<int>(0,4);
        switch(choice){
            case 1:
                handleProductManagement(store.getProductManager());
                break;
            case 2:{
                try{
                    std::cout<<"Enter product's name: ";
                    std::string name=Util::getValidatedStringInput();
                    std::cout<<"Enter product's price: ";
                    double price=Util::getValidatedNumberInput<double>(0);
                    std::cout<<"Enter product's quantity: ";
                    int quantity=Util::getValidatedNumberInput<int>(0);
                    store.getProductManager().addProduct(name,price,quantity);
                    std::cout<<"Product's successfully added to the store"<<std::endl;
                    Util::pressEntertoContinue();
                }
                catch(const InvalidProductException& e){
                    std::cout<<e.what()<<std::endl;
                    Util::pressEntertoContinue();
                }
                break;
            }
            case 3:
                handleOrderManagement(store.getOrderManager());
                break;
            case 4:
                return;
        }
        
    }
}