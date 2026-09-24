#pragma once

#include <iostream>
#include <string>

class Player;
class Enemy;

struct Battle {
    Player* player;
    Enemy* enemy;
    static void runBattle(Player* player, Enemy* enemy);
    static void playerAttack();
    static void enemyAttack();
    static void viewStats(Player* player, Enemy* enemy);

};