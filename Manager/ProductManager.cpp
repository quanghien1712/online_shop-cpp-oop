#include "ProductManager.hpp"
#include "Core/Exception.hpp"
#include <fstream>
#include <sstream>

void ProductManager::addProduct(const std::string& productname,double price,int quantity){
    Product* storeProduct=findProductbyName(productname);
    if(storeProduct!=nullptr){
        throw InvalidProductException("Product existed!");
    }
    Product newProduct=Product(productname,quantity,price);
    productList.push_back(newProduct);
}

void ProductManager::removeProduct(int ProductID,int quantity){
    Product* product=&productList[ProductID];
    if(product->hasStock(quantity)){
        product->reduceStock(quantity);
    }
    else productList.erase(productList.begin()+ProductID);
}

Product* ProductManager::findProductbyName(const std::string& name){
    for(Product& x:productList){
        if(x.getName()==name){
            return &x;
        }
    }
    return nullptr;
}

Product* ProductManager::findProductbyId(int id){
    return &productList[id];
}


std::vector<Product>& ProductManager::getProductList(){
    return productList;
}

void ProductManager::loadProductsFromFile(const std::string& filename){
    std::ifstream input(filename);
    if(!input) return;
    std::string line;
    while(std::getline(input,line)){
        std::stringstream ss(line);
        std::string productname;ss>>productname;
        double price;ss>>price;
        int quantity;ss>>quantity;
        addProduct(productname,price,quantity);
    }
    input.close();
}

void ProductManager::saveProductsToFile(const std::string& filename){
    std::ofstream output(filename);
    if(!output) return;
    for(const auto& product:productList){
        output<<product.getName()<<" "<<product.getPrice()<<" "<<product.getQuantity()<<"\n";
    }
    output.close(); 
}