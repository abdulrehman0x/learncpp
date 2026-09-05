#include <iostream>
#include <string>
#include <cmath>

int main(){
    int num1;
    int num2;
    std::string operation;
    std::cout << "What Mathematical operation you want to perform?(addition/substraction/division/multiplication/exponent): ";
    std::cin >> operation;
    std::cout << "Enter a number: ";
    std::cin >> num1;
    if(operation == "exponent"){
        std::cout << num1*num1;
    }
    else{
        std::cout << "Enter 2nd number: ";
        std::cin >> num2;
    }
    if(operation =="addition"){
        std::cout << num1 + num2;
    }
    else if(operation =="substraction") {
        std::cout << abs(num1-num2);
    }
    else if (operation == "division"){
        std::cout << num1/num2;
    }
    else if(operation =="multiplication"){
        std::cout << num1*num2;
    }

}
