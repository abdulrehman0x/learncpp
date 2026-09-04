#include <iostream>
#include <string>

int main(){
    int year;
    int age;
    std::cout <<"Enter your birth year: "<< std::flush;
    std::cin >> year;
    age = (2026 - year);
    std::cout <<"Your age is:"<< age;
    return 0;



}
