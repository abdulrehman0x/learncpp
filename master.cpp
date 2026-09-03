#include <iostream>

int main(){
    int marks;
    std::string field;
    std::cout << "Which Department are you from? (ICS/PreMed/Fsc): ";
    std::cin >> field;
    std::cout << "Enter your obtained marks: ";
    std::cin >> marks;
    float percentage;
    if (field == "ICS" ||field == "Fsc"){
         percentage = (static_cast<float>(marks)/510)*100;
    }
    else{
         percentage = (static_cast<float>(marks)/550)*100;
    }
    std::cout <<"Your percentage is: "<< percentage << "\n";
    if(percentage >= 85){
        std::cout << "Grade = A+";
    }
    else if(percentage >=80){
        std::cout << "Grade = A";
    }
    else if (percentage >= 70){
        std::cout<<"Grade = B+";
    }
    else if(percentage >= 65){
        std::cout << "Grade = B";
    }
    else{
        std::cout << "Grade = Ungraded/Failure";
    }
    return 0;

}
