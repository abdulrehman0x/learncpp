#include <iostream>

int main(){
    int num1;
    std::cout << "Enter a number:"<< std::endl;
    std::cin >> num1;
    for(int i = 1; i<=10; ++i){
        std::cout << num1 << "x" << i << "="<< num1*i << "\n";

    }
    return 0;
}
