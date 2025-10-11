#include "Core/ShopSystem.hpp"
#include "UI/MenuSystem.hpp"
#include<memory>

int main(){
    std::unique_ptr<ShopSystem> store = std::make_unique<ShopSystem>();
    MenuSystem SystemApplication;
    SystemApplication.handleMainMenu(*store);
    return 0;
}