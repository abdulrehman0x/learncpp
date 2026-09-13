#include <iostream>
#include <string>

void player_stats(int player_hp, int boss_hp){
    std::cout << "\n| Player HP = " << player_hp << " | Boss HP = " << boss_hp << " |";
}

int main (){
    int player_hp = 50;
    int boss_hp = 50;
    int choice;
    std::cout <<"-------------------------------" << std::endl;
    std::cout << "       BOSS BATTLE GAME" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    player_stats(player_hp,boss_hp);


    while(player_hp > 0 && boss_hp > 0){
        return 0;

    }
}
