#include "Product.hpp"
#include "Core/Exception.hpp"
#include<iostream>

Product::Product(const std::string& _name,int _quantity,double _price):
    name(_name),price(_price),quantity(_quantity)
{}

const std::string& Product::getName() const{
    return this->name;
}

void Product::setPrice(double newprice){
    this->price=newprice;
}

void Product::setQuantity(int newquantity){
    this->quantity=newquantity;
}

int Product::getQuantity()const{
    return this->quantity;
}

double Product::getPrice()const{
    return this->price;
}

bool Product::hasStock(int requestedQuantity) const{
    return quantity>=requestedQuantity;
}

void Product::addStock(int amount){
    quantity+=amount;
}

void Product::reduceStock(int amount){
    if(amount>quantity){
        amount=quantity;
    }
    quantity-=amount;
}





