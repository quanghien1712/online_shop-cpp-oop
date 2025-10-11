#ifndef SHOPSYS_HPP
#define SHOPSYS_HPP

#include<memory>
#include "Manager/ProductManager.hpp"
#include "Manager/OrderManager.hpp"
#include "Manager/UserManager.hpp"



class ShopSystem{
    private:
        std::unique_ptr<ProductManager> productManager;
        std::unique_ptr<OrderManager> orderManager;
        std::unique_ptr<UserManager> userManager;
    public:
        ShopSystem();
        ~ShopSystem();
        ProductManager& getProductManager();
        OrderManager& getOrderManager();
        UserManager& getUserManager();
        void initializeDefaultAdmin();
};

#endif 