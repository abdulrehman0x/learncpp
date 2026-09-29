#include <iostream>

int main (){
    double num1,num2;
    double avg;
    std::cout << "Enter a number: ";
    std::cin >> num1;
    std::cout << "\nEnter 2nd number: ";
    std::cin >> num2;
    avg = (num1 + num2 )/2.0;
    if(num1 == 0 || num2 == 0){
        std::cout << "You have entered an invalid number!!, Please try again!";
    }
    else{
        std::cout << "\n Average is = " << avg;
    }
    return 0;

}
