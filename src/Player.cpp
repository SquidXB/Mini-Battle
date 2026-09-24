#include "../include/Player.h"
#include <iostream>

Player::Player(const std::string name)
    : name(name), health(100), level(1) {
        // std::cout << name << " created!" << std::endl;
    }

Player::~Player() {
    std::cout << name << " has been defeated!" << std::endl;
}

void Player::attackEnemy() {
    std::cout << "Attacked enemy for 0 dmg" << std::endl;
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

int& Player::getLevel() {
    return level;
}

int& Player::getDmg() {
    return attackDmg;
}