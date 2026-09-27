#pragma once

#include <string>
// #include <map>
class Enemy;

class Player {
private:
    std::string name;
    int health;
    int maxHealth;
    int level;
    int xp;
    int attackDmg;
    int minDmg;
    int maxDmg;
    //std::map<items, int> inventory;   healing 1 & 2 (5-10, 15-25) dmg (1.05, 1.1), ...
    Enemy* enemy;

public:
    Player(const std::string name);
    ~Player();
    void healSelf();

    std::string& getName();
    int& getHealth();
    int& getMaxHealth();
    int& getLevel();
    int& getXp();
    int& getDmg();
    int& getMinDmg();
    int& getMaxDmg();
};