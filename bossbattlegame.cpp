#include <iostream>

void player_stats(int player_hp, int boss_hp){
    std::cout << "\n| Player HP = " << player_hp << " | Boss HP = " << boss_hp << " |";
}

int calc_damage(int attack){
    return attack;
}
int main (){
    int player_hp = 50;
    int boss_hp = 50;
    int choice;
    int damage;
    int enemy_damage;
    std::cout <<"-------------------------------" << std::endl;
    std::cout << "       BOSS BATTLE GAME" << std::endl;
    std::cout << "-------------------------------" << std::endl;


    while(player_hp > 0 && boss_hp > 0){
        player_stats(player_hp,boss_hp);
        std::cout << "\nChoose Your Attack type:\n"<< "Enter 1 to Punch the Boss \n"<<"Enter 2 to Kick the boss\n" << "Selection: ";
        std::cin >> choice;
        switch(choice){
            case 1:{
                damage = calc_damage(10);
                boss_hp = boss_hp - damage;
                std::cout << "Thats a solid blow!!\nYou dealt a " << damage <<" damage to your enemy" << std::endl;
                break;
                }
            case 2:{
                damage = calc_damage(20);
                boss_hp = boss_hp - damage;
                std::cout << " That was a Nasty kick!\n"<< damage << " damage dealt to the enemy" << std::endl;
                break;
                }
            default:{
                std::cout << "Invalid insertion!";
                break;
                }

        }
        if (boss_hp > 0){
            enemy_damage = calc_damage(5);
            player_hp = player_hp- enemy_damage;
        }
        if( player_hp > 0){
            std::cout << " You Won!!";
        }
        else{
            std::cout << "Boss Won, You lost!";
        }
        return 0;

    }
}
