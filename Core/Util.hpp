#ifndef UTILS_HPP
#define UTILS_HPP

#include<limits>
#include<iostream>
#include<string>
#include<sstream>

class Util{
    public:
        static void clearScreen();
        static void pressEntertoContinue();
        template <typename T>
        static T getValidatedNumberInput(T min, T max=std::numeric_limits<T>::max());
        static std::string getValidatedStringInput();
};

template <typename T>
T Util::getValidatedNumberInput(T min, T max){
    T value;
    std::string input;
    while(true){
        std::getline(std::cin,input);
        if (input.empty()) continue; 
        std::stringstream ss(input);
        if(ss>>value&&ss.eof()){
            if(value > min && value <= max){
                return value;
            }
        }
        std::cout << "Invalid Input. Please enter a valid number: ";
    }
}

#endif