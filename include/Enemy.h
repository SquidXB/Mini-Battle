#pragma once

#include <iostream>
#include <string>

class Player;

class Enemy {
private:
    std::string name;
    int health;
    int attackDmg;
    Player* player;
public:
    Enemy();
    ~Enemy();
    void attack();
    std::string& getName();
    int& getHealth();
};