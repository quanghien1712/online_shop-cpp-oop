#ifndef CART_HPP
#define CART_HPP

#include <vector>
#include "Product.hpp"

class ProductManager;

class Cart{
    private:
        std::vector<Product> cart;
        double total;
    public:
        void updatetotal(int price,int quantity);
        double gettotal()const;
        Product* findProductbyName(const std::string& productName);
        void addToCart(int ProductId,int quantity,ProductManager& productManager);
        void removefromCart(int CartId,int quantity);
        void clearCart();
        const std::vector<Product>& getItems() const;
};  


#endif 