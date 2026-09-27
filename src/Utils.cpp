#include <random>
#include <chrono>
#include "../include/Utils.h"
#include "../include/Player.h"

int Utils::randomNum(int min, int max) {
    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())}; //uses chrono to seed random
    std::uniform_int_distribution rand {min, max}; //generates random number between min and max values
    return rand(mt);
}

int Utils::randomizeXp() {
    return 0;
}
// randomizeDrop();
int Utils::randomHeal() {
    return 0;
}
/*
int Utils::randomizeEnemyDmg() {
    return 0;
}
int Utils::randomizeEnemyMove() {
    return 0;
}
    */