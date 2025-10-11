#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include<exception>
#include<string>

class ShopException : public std::exception{
    private:
        std::string message;
    public:
        explicit ShopException(const std::string& msg):message(msg){}
        const char* what() const noexcept override{
            return message.c_str();
        }
};

class InvalidProductException : public ShopException{
    public:
        explicit InvalidProductException(const std::string& msg):ShopException(msg){}
};

class InvalidOrderException: public ShopException{
    public:
        explicit InvalidOrderException(const std::string& msg):
        ShopException(msg){}
};




#endif