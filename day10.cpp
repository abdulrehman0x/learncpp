#include <iostream>

int quadruple(int num){
    return num*4;
}
int main (){
    int num1;
    std::cout << "Enter a number: ";
    std::cin >> num1;
    int result = quadruple(num1);
    std::cout << result;
    return 0;
}
