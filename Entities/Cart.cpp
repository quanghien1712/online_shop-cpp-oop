#include "Cart.hpp"
#include "Manager/ProductManager.hpp"
#include "Core/Exception.hpp"



void Cart::updatetotal(int price,int delta) {
    total+=delta*price;
}

double Cart::gettotal()const{
    return total;
}

Product* Cart::findProductbyName(const std::string& productName){
    for(int i=0;i<(int)cart.size();++i){
        if(cart[i].getName()==productName){
            return &cart[i];
        }
    }   
    return nullptr;
}


void Cart::addToCart(int ProductId,int quantity,ProductManager& productManager){
    Product* storeProduct=productManager.findProductbyId(ProductId);
    Product* cartProduct=findProductbyName(storeProduct->getName());
    if(cartProduct==nullptr){
        if(quantity>storeProduct->getQuantity()){
            throw InvalidProductException("Not enough stock available");
        }
        cart.emplace_back(storeProduct->getName(),quantity,storeProduct->getPrice());
    }
    else{
        int currentQuantity=cartProduct->getQuantity();
        if(storeProduct->hasStock(currentQuantity+quantity)){
            cartProduct->addStock(quantity);
        }
        else throw InvalidProductException("Not enough stock available");
    }
    updatetotal(storeProduct->getPrice(),quantity);
}

void Cart::removefromCart(int CartId,int quantity){
    Product* cartProduct=&cart[CartId];
    cartProduct->reduceStock(quantity);
    if(cartProduct->getQuantity()==0){
        cart.erase(cart.begin()+CartId);
    }
    updatetotal(cartProduct->getPrice(),-quantity);
}

void Cart::clearCart(){
    cart.clear();
    total=0;
}

const std::vector<Product>& Cart::getItems() const{
    return cart;
}
