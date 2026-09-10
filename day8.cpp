#include <iostream>

int main() {
    int num;
    unsigned long long fact = 1; // Use unsigned long long to handle larger results

    std::cout << "Enter Number: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
        return 1;
    }

    // Loop runs from 1 up to 'num' and accumulates the product
    for (int i = 1; i <= num; ++i) {
        fact *= i;
    }

    std::cout << "Factorial of " << num << " is: " << fact << std::endl;

    return 0;
}
