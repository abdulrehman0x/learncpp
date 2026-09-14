#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string field;
    int marks;

    std::cout << "Which Department are you from? (ICS/PreMed/Fsc):\n" << std::flush;
    std::cin >> field;

    std::cout << "Enter your obtained marks:\n" << std::flush;
    std::cin >> marks;

    float percentage;
    if (field == "ICS" || field == "Fsc") {
        percentage = (static_cast<float>(marks) / 510.0f) * 100.0f;
    } else {
        percentage = (static_cast<float>(marks) / 550.0f) * 100.0f;
    }

    std::cout << "Your percentage is: " << percentage << "%\n" << std::flush;

    if (percentage >= 85) std::cout << "Grade = A+\n" << std::flush;
    else if (percentage >= 80) std::cout << "Grade = A\n" << std::flush;
    else if (percentage >= 70) std::cout << "Grade = B+\n" << std::flush;
    else if (percentage >= 65) std::cout << "Grade = B\n" << std::flush;
    else std::cout << "Grade = Ungraded/Failure\n" << std::flush;

    return 0;
}
