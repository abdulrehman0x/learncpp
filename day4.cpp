#include <iostream>

int main(){
    int row = 3;

    for(int i = row; i>= 1; --i){
        for(int j = row; j>=i; --j)
            std::cout << "$";
        std::cout << "\n";
    }
    return 0;

}
