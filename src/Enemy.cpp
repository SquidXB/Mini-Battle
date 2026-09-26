#include "../include/Enemy.h"
#include <iostream>

Enemy::Enemy()
    : name("Enemy"), health(100), attackDmg(5) {  //Health & Dmg will depend on type
        // std::cout << name << " created!" << std::endl;
    }

Enemy::~Enemy() {
    std::cout << name << " has been defeated!" << std::endl;
}

void Enemy::attack() {
    std::cout << "attacked player for " << attackDmg << "!" << std::endl;
}

std::string& Enemy::getName() {
    return name;
}

int& Enemy::getHealth() {
    return health;
}