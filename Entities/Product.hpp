#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include<string>


class Product{
    private: 
        std::string name;
        double price;
        int quantity;
    public:
        Product(const std::string& name,int quantity,double price );
        void setQuantity(int newquantity);
        void setPrice(double newprice);
        double getPrice() const;
        int getQuantity() const;
        const std::string& getName() const;
        bool hasStock(int requestedQuantity) const;
        void addStock(int amount);
        void reduceStock(int amount);
};


#endif 
