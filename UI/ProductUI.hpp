#ifndef PRODUCTUI_HPP
#define PRODUCTUI_HPP

#include "Entities/Product.hpp"
#include "Core/Exception.hpp"
#include<vector>
#include<iostream>
#include<iomanip>

class ProductUI{
    public:
        static void displayProductCatalogue(const std::vector<Product>& productList){
            std::cout<<"======Product Catalogue======"<<std::endl;
            std::cout<<std::endl;
            if((int)productList.size()==0){
                throw InvalidProductException("Store has no stock");
            }
            for(int i=0;i<(int)productList.size();++i){
                std::cout<<i<<". ";
                displayProductDetail(productList[i]);
            }
            std::cout<<std::endl;
        }
        static void displayProductDetail(const Product& product){
            std::cout<<product.getName()<<std::endl;
            std::cout<<"Price: "<<std::fixed<<std::setprecision(2)<<product.getPrice()<<std::endl; 
            std::cout<<"Quantity: "<<product.getQuantity()<<std::endl;
            std::cout<<std::endl;
        }
};


#endif