#include <iostream>
#include <cmath>

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    int temp = std::abs(number);
    int count = 0;
    if(temp == 0){
        count = count + 1;

    }
    else{
        while(temp>1){
            temp /= 10;
            count++;
        }
    }
std::cout << "Digit count: " << count<<"\n";

}


#include <iostream>
#include <cmath>

int main(){
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    if(num%2 == 0){
        std::cout << "its an even number!!";
    }
    else{
        std::cout << "its an odd number!!";
    }
}
