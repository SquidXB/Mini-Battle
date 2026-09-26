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
    //std::map<items, int> inventory;
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
};