#ifndef PRODUCT_MANAGER_HPP
#define PRODUCT_MANAGER_HPP

#include "Entities/Product.hpp"
#include<vector>
#include<string>

class ProductManager{
    private:
        std::vector<Product> productList;
    public:
        void addProduct(const std::string& productname,double price,int quantity);
        void removeProduct(int ProductID,int quantity);
        Product* findProductbyName(const std::string& name);
        Product* findProductbyId(int id);
        std::vector<Product>& getProductList();
        void loadProductsFromFile(const std::string& filename);
        void saveProductsToFile(const std::string& filename);

};


#endif