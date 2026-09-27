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
    static int randomNum(int min, int max);
    
    static int randomizeXp();
    // randomizeDrop();
    static int randomHeal();
    // static int randomizeEnemyDmg();  NOT NECESSARY : WILL BE CALCULATED IN Battle::enemyAttack()
    // static int randomizeEnemyMove(); NOT NECESSARY : WILL BE CALCULATED IN Battle
};