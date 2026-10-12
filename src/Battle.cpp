#include <iostream>
#include "../include/Battle.h"
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Utils.h"

class Player;
class Enemy;
static int choice, minRange = 0, maxRange;

void Battle::viewStats(Player* player, Enemy* enemy) {
    std::cout << player->getName() << ": Level " << player->getLevel() << " Knight" << std::endl << "HP: " << player->getHealth() << "/" << player->getMaxHealth() << std::endl << "DMG: " << player->getDmg() << std::endl;
    std::cout << std::endl;
    std::cout << enemy->getName() << ": Level x " << enemy->getName() << std::endl << "HP: " << enemy->getHealth() << "/" << enemy->getMaxHealth() << std::endl << "DMG: x" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Attack" << std::endl << "2. Heal" << std::endl << "3. View Stats" << std::endl << "4. Run" << std::endl;
}

void Battle::playerTurn(Player* player, Enemy* enemy) {
    choice = 0;
    while (choice != 1 && choice != 4) {
    std::cout << "Choose a move: ";
    std::cin >> choice;
    switch (choice) { 
        case 1: 
            Battle::playerAttack(player, enemy);
            break;  //call player's attack & add modifier of utils, return from utils # of dmg points to deduct from enemy, add message to tell how much damage
        case 2: 
            if (player->getHealth() < player->getMaxHealth()) {
                Battle::playerHeal(player);
                Battle::playerTurn(player, enemy);
            }
            else {
                std::cout << "You already have full health!" << std::endl;
            }
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
}

void Battle::playerAttack(Player* player, Enemy* enemy) {
    int dmgDealt = (player->getMinDmg() + (player->getLevel() / 5)) + Utils::randomNum(minRange, maxRange);
    // int dmgDealt = player->getDmg() + Utils::randomNum();
    enemy->getHealth() -= dmgDealt;
    std::cout << "Attacked " << enemy->getName() << " for " << dmgDealt << " dmg!" << std::endl;
}

void Battle::playerHeal(Player* player) {
    int choiceH, posHealth;
    std::cout << "Which potion would you like to use?" << std::endl << "You have:" << std::endl;
    std::cout << "- Health Lvl 1 x #" << std::endl << "- Health Lvl 2 x #" << std::endl;
    std::cin >> choiceH;
    switch (choiceH){
        case 1: 
            posHealth = Utils::randomNum(5, 10);
            break;        
        case 2:
            posHealth = Utils::randomNum(7, 15);
            break;
        default:
            std::cout << "Invalid choice. Try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            Battle::playerHeal(player);
    }
    if (choiceH == 1 || choiceH == 2) {
    player->getHealth() + posHealth > player->getMaxHealth() ? player->getHealth() = player->getMaxHealth() : player->getHealth() += posHealth; //checks if posHeal does too much
    std::cout << "Healed " << player->getName() << " for " << posHealth << "!" << std::endl;
    }
}

void Battle::enemyTurn(Player* player, Enemy* enemy) {
    int enemyMove = Utils::randomNum(1, 1);
    switch (enemyMove) {
        case 1:
            Battle::enemyAttack(player, enemy);
            return;
        /*case 2:
            return;
        case 3:
            return;*/
    }
}

void Battle::enemyAttack(Player* player, Enemy* enemy) {
    int dmgDealt = enemy->getAttackDmg() + Utils::randomNum(0, 2);
    player->getHealth() -= dmgDealt;
    std::cout << "Attacked " << player->getName() << " for " << dmgDealt << " dmg!" << std::endl;
}

void Battle::runBattle(Player* player, Enemy* enemy) {
    maxRange = player->getLevel() > 20 ? 5 : (player->getLevel() / 5) + 1; 
    std::cout << "Battle has begun!" << std::endl;
    while (((player->getHealth() > 0) && (enemy->getHealth()) > 0) && choice != 4) {
        Battle::viewStats(player, enemy);
        Battle::playerTurn(player, enemy);
        if (choice != 4 && enemy->getHealth() > 0) {
            std::cout << std::endl << "Enemy's turn:" << std::endl;
            Battle::enemyTurn(player, enemy);
        }
    }
    std::cout << "Battle has ended!" << std::endl;
}
