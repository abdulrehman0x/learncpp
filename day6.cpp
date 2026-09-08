#include <iostream>
#include <string>

int main (){
    std::cout << "\n---------------------------\n";
    std::cout << " C++ Day predictor Program";
    std::cout << "\n---------------------------\n";
    int day ;
    std::cout << "Enter current day(1-7): ";
    std::cin >> day;
    switch(day){
        case 1:
            std::cout <<"Next day is Monday";
            break;
        case 2:
            std::cout << "Next day is Tuesday";
            break;
        case 3:
            std::cout << "Next day is Wednesday";
            break;
        case 4:
            std::cout<< "Next day is Thursday";
            break;
        default:
            std::cout << "Invalid day!!";
            break;
    }


}
