#include <iostream>
#include "../include/Battle.h"
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Utils.h"

class Player;
class Enemy;
static int choice;

void Battle::viewStats(Player* player, Enemy* enemy) {
    std::cout << player->getName() << ": Level " << player->getLevel() << " Knight" << std::endl << "HP: " << player->getHealth() << std::endl << "DMG: " << player->getDmg() << std::endl;
    std::cout << std::endl;
    std::cout << enemy->getName() << ": Level x " << enemy->getName() << std::endl << "HP: " << enemy->getHealth() << std::endl << "DMG: x" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Attack" << std::endl << "2. Heal" << std::endl << "3. View Stats" << std::endl << "4. Run" << std::endl;
}

void Battle::playerTurn(Player* player, Enemy* enemy) {
    choice = 0;
    std::cout << "Choose a move: ";
    std::cin >> choice;
    try{
        switch (choice) { 
            case 1: 
                Battle::playerAttack(player, enemy);
                break;  //call player's attack & add modifier of utils, return from utils # of dmg points to deduct from enemy, add message to tell how much damage
            case 2: 
                if (player->getHealth() == player->getMaxHealth()) {
                    std::cout << "You already have full health!" << std::endl;
                    Battle::playerTurn(player, enemy);
                }
                // Battle::playerHeal();
                break;    //call player's heal (eventually if they have potions), & add rand to see if successful & for how much, add message
            case 3: 
                Battle::viewStats(player, enemy);
                break;
            case 4:
                std::cout << player->getName() << " has run away!" << std::endl; 
                return;
            default: 
                std::cout << "Invalid input. Try again!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                Battle::playerTurn(player, enemy);
        }
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Invalid response. Try again!";
        Battle::playerTurn(player, enemy);
    }
}

void Battle::playerAttack(Player* player, Enemy* enemy) {
    int dmgDealt = player->getDmg() + Utils::randomNum();
    enemy->getHealth() -= dmgDealt;
    std::cout << "Attacked " << enemy->getName() << " for " << dmgDealt << " dmg!" << std::endl;
}

void Battle::playerHeal(Player* player) {
    //std::cout << player->getName() " healed for " __;
}

void Battle::runBattle(Player* player, Enemy* enemy) {
    std::cout << "Battle has begun!" << std::endl;
    while (((player->getHealth() > 0) && (enemy->getHealth()) > 0) && choice != 4) {
        Battle::viewStats(player, enemy);
        Battle::playerTurn(player, enemy);
        if (choice != 4) {
            std::cout << "Enemy turn here" << std::endl;
            //Battle::enemyTurn(player, enemy);
        }
    }
    std::cout << "Battle has ended!" << std::endl;
}
