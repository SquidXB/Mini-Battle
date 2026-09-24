#pragma once

#include <string>
// #include <map>
class Enemy;

class Player {
private:
    std::string name;
    int health;
    int level;
    int attackDmg;
    //std::map<items, int> inventory;
    Enemy* enemy;

public:
    Player(const std::string name);
    ~Player();
    void attackEnemy();
    void healSelf();

    std::string& getName();
    int& getHealth();
    int& getLevel();
    int& getDmg();
};