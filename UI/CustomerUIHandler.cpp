#include "CustomerUIHandler.hpp"
#include "Core/Exception.hpp"
#include "Core/Util.hpp"
#include "Customer.hpp"
#include "ShopSystem.hpp"
#include "Manager/ProductManager.hpp"
#include "Manager/OrderManager.hpp"
#include "ProductUI.hpp"
#include "Entities/Cart.hpp"
#include "OrderUI.hpp"

#include <iostream>
#include <iomanip>


void CustomerUIHandler::displayMyCart(const std::vector<Product>& items,double total ){
    std::cout<<"======Your Cart====="<<std::endl;
    std::cout<<std::endl;
    if(items.empty()){
        throw InvalidProductException("Cart is empty");
    }
    for(int i=0;i<(int)items.size();++i){
        std::cout<<i<<". ";
        ProductUI::displayProductDetail(items[i]);
    }
    std::cout<<std::endl;
    std::cout<<"->Total: "<<std::fixed<<std::setprecision(2)<<total<<std::endl;
} 

void CustomerUIHandler::displayCartOption(){
    std::cout<<std::endl;
    std::cout<<"1. Checkout"<<std::endl;
    std::cout<<"2. Remove Item"<<std::endl;
    std::cout<<"3. Clear cart"<<std::endl;
    std::cout<<"4. Back to Menu"<<std::endl;
    std::cout<<std::endl;
}

void CustomerUIHandler::displayShoppingOption(){
    std::cout<<std::endl;
    std::cout<< "1. Add to Cart"<<std::endl;
    std::cout<< "2. Back to Menu"<<std::endl;
    std::cout<< std::endl;
}

void CustomerUIHandler::displayCustomerMenu(){
    std::cout<< "========== CUSTOMER MENU =========="<<std::endl;
    std::cout<< "| 1. View & Shop Products         |"<<std::endl;
    std::cout<< "| 2. Manage Cart                  |"<<std::endl;
    std::cout<< "| 3. View Orders                  |"<<std::endl;
    std::cout<< "| 4. Logout                       |"<<std::endl;
    std::cout<< "==================================="<<std::endl;
    std::cout<<std::endl;
}

void CustomerUIHandler::handleShoppingMenu(Customer* customer,ProductManager& productManager){
    while(1){
        try{
            Util::clearScreen();
            std::vector<Product> productCatalogue=productManager.getProductList();
            ProductUI::displayProductCatalogue(productCatalogue);
            displayShoppingOption();
            std::cout<<"Enter your choice: ";
            int getchoice=Util::getValidatedNumberInput<int>(0,2);
            switch(getchoice){
                case 1:{
                    std::cout<<"Enter product's id to buy: ";
                    int prodId=Util::getValidatedNumberInput<int>(-1,(int)productCatalogue.size()-1);
                    std::cout<<"Enter product's quantity to buy: ";
                    int quantity=Util::getValidatedNumberInput<int>(0);
                    const Product& storeProduct=*productManager.findProductbyId(prodId);
                    try{
                        customer->getCart()->addToCart(storeProduct,quantity);
                        std::cout<<"Product's successfully added"<<std::endl;
                    }
                    catch(const InvalidProductException& e){
                        std::cerr<<e.what()<<std::endl;
                    }
                    break;
                }
                case 2:
                    return;
            }
            Util::pressEntertoContinue();
        }
        catch (const InvalidProductException& e){
            std::cerr<<e.what()<<std::endl;
            Util::pressEntertoContinue();
            return;
        }
    }
} 


void CustomerUIHandler::handleCart(Customer* customer,ShopSystem& store){
    while(1){
        try{
            Util::clearScreen();
            Cart* CustomerCart=customer->getCart();
            const std::vector<Product> CartItems=CustomerCart->getItems();
            displayMyCart(CartItems,CustomerCart->gettotal());
            displayCartOption();
            std::cout<<"Enter your choice: ";
            int choice=Util::getValidatedNumberInput<int>(0,4);
            switch(choice){
                case 1:{
                    customer->checkout(store.getOrderManager(),store.getProductManager());
                    std::cout<<"Check out successfully"<<std::endl;
                    break;
                }
                case 2:{
                    int cartId=Util::getValidatedNumberInput<int>(-1,CartItems.size()-1);
                    int quantity=Util::getValidatedNumberInput<int>(0);
                    CustomerCart->removefromCart(cartId,quantity);
                    std::cout<<"Product's deleted successfully"<<std::endl;
                    break;
                }
                case 3:{
                    CustomerCart->clearCart();
                    std::cout<<"Cart has been cleared"<<std::endl;
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

void CustomerUIHandler::displayMyOrder(const std::vector<Order*>& orderHistory){
    std::cout<<"======Your Order History====="<<std::endl;
    std::cout<<std::endl;
    if((int)orderHistory.size()==0){
        throw InvalidOrderException("Your order is empty");
    }
    for(int i=0;i<(int)orderHistory.size();++i){
        std::cout<<i<<"."<<std::endl;
        OrderUI::displayOrderDetail(orderHistory[i]);
    }
}


void CustomerUIHandler::handleOrder(Customer* customer){
    //can add options in the future;
    //now only display Order
    while(1){
        Util::clearScreen();
        try{
            displayMyOrder(customer->getOrderHistory());
            std::cout<<std::endl;
            std::cout<<"1. Back to menu";
            std::cout<<std::endl;
            std::cout<<"Enter your choice: ";
            int choice=Util::getValidatedNumberInput<int>(0,1);
            switch(choice){
                case 1:
                    return;
            }
        }
        catch(const InvalidOrderException& e){
            std::cerr<<e.what()<<std::endl;
            Util::pressEntertoContinue();
            return;
        }   
    }
    
}


void CustomerUIHandler::handleCustomerMenu(Customer* customer,ShopSystem& store){
    while(1){
        Util::clearScreen();
        displayCustomerMenu();
        std::cout<<"Enter your choice: ";
        int choice=Util::getValidatedNumberInput<int>(0,4);
        switch(choice){
            case 1:
                handleShoppingMenu(customer,store.getProductManager());
                break;
            case 2:
                handleCart(customer,store);
                break;
            case 3:
                handleOrder(customer);
                break;
            case 4:
                return;
        }
    }
}