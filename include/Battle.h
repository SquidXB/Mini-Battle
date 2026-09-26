#pragma once

#include <iostream>
#include <string>

class Player;
class Enemy;

struct Battle {
    Player* player;
    Enemy* enemy;
    static void runBattle(Player* player, Enemy* enemy);
    static void playerTurn(Player* player, Enemy* enemy);
    static void playerAttack(Player* player, Enemy* enemy);
    static void playerHeal(Player* player);
    static void enemyAttack();
    static void viewStats(Player* player, Enemy* enemy);

};