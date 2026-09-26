#include <random>
#include <chrono>
#include "../include/Utils.h"

int Utils::randomNum() {
    std::mt19937 mt{static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())}; //uses chrono to seed random
    std::uniform_int_distribution rand5 {0, 5}; //generates random number between 0 and 5
    return rand5(mt);
}

int Utils::randomizeXp() {

}
// randomizeDrop();
int Utils::randomHeal() {

}
int Utils::randomizeEnemyDmg() {

}
int Utils::randomizeEnemyMove() {

}