#include "Util.hpp"
#include<limits>
#include<iostream>

void Util::clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Util::pressEntertoContinue(){
    std::cout<<"Press Enter to continue...";
    std::cin.get();
}

std::string Util::getValidatedStringInput(){
    std::string input;
    std::getline(std::cin,input);
    return input;
}