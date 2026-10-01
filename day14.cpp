#include <iostream>

int main(){
    int marks;
    std::cout << "Enter your marks : ";
    std::cin >> marks;
    std::string result =  (marks >=50)? "pass" : "failed";
    std::cout << result;

}
