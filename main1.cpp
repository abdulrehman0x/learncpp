#include <iostream>
#include <cmath>

int main (){
    float num;
    std::cout << "Enter a Number: ";
    std::cin >> num;
    if(num > 0){
        std::cout << "Entered number is positive!! ";
    }
    else if (num == 0){
        std::cout << "Entered number is equal to zero!";
    }
    else{
        std::cout << "Entered number is negative!!";
    }
}
