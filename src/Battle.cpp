#include <iostream>
#include "../include/Battle.h"
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Utils.h"

class Player;
class Enemy;

void Battle::viewStats(Player* player, Enemy* enemy) {
    std::cout << player->getName() << ": Level " << player->getLevel() << " Knight" << std::endl << "HP: " << player->getHealth() << std::endl << "DMG: " << player->getDmg() << std::endl;
    std::cout << std::endl;
    std::cout << enemy->getName() << ": Level x " << enemy->getName() << std::endl << "HP: " << enemy->getHealth() << std::endl << "DMG: x" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Attack" << std::endl << "2. Heal" << std::endl << "3. View Stats" << std::endl << "4. Run" << std::endl;
}

void Battle::runBattle(Player* player, Enemy* enemy) {
    std::string choice;
    std::cout << "Battle has begun!" << std::endl;
    if ((player->getHealth() && enemy->getHealth()) > 0) {
        Battle::viewStats(player, enemy);
    }
}