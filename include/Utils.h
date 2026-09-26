#pragma once
/* Random xp distributions
    Random drops
    Random heal chance
    Random attack Dmg from enemy
    Random enemy move
*/
class Player;
class Enemy;

struct Utils {
    static int randomNum();
    static int randomizeXp();
    // randomizeDrop();
    static int randomHeal();
    static int randomizeEnemyDmg();
    static int randomizeEnemyMove();
};