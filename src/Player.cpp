#include "../include/Player.h"
#include <iostream>

Player::Player(const std::string name)
    : name(name), health(100), maxHealth(100), minDmg(5), maxDmg(20), level(1), xp(0), attackDmg(5) {
        // std::cout << name << " created!" << std::endl;
    }

Player::~Player() {
    std::cout << name << " has been defeated!" << std::endl;
}

void Player::healSelf() {
    std::cout << "Healed " << name << "!" << std::endl;
}

std::string& Player::getName() {
    return name;
}

int& Player::getHealth() {
    return health;
}

int& Player::getMaxHealth() {
    return maxHealth;
}

int& Player::getLevel() {
    return level;
}

int& Player::getXp() {
    return xp;
}

int& Player::getDmg() {
    return attackDmg;
}

int& Player::getMinDmg() {
    return minDmg;
}

int& Player::getMaxDmg() {
    return maxDmg;
}