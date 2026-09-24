#include <iostream>
#include <memory> //include for smart ptrs
#include "include/Player.h"
#include "include/Enemy.h"
#include "include/Battle.h"
// Use static for structs (when not tied to certain users)

/* important string/array? methods:
substr(start, end)
append(string)
at(index)
front() & back() - first & last char
begin() & end() - iterators for loops
erase (startpos, length)
length()/size()
insert(char, pos)*/

// GO BACK OVER OPERATOR OVERLOADING
int main() {
    Player p("Squid");
    Enemy e;
    Battle::runBattle(&p, &e);
    return 0;  
}

/* Idea: mini inline rpg style combat game
Choose to battle, provides random enemy w/ range of health, drop range of xp (all Enemy class)
Higher XP level means more health & attack for player (all player)
Attack: choose to attack w/ damage amount, success rate random, slightly more consistent with higher level (Battle class)

Player name: Level x Knight
HP:
Attack:

Enemy: Name/type
HP:
Attack:

1. Attack
2. Heal
3. View Stats (?)
4. Run

Player Class (__ pointer):
Handles player: Name, health, xp, attack

Enemy (shared pointer?):
Basic first, then come back to inheritance

Battle (unique?):
Organize fight structure (turn order, options? etc)

Utils:
For random (enemy attacks, critical? healing amount, enemy selection)
***When player chooses attack, utils handles rng of if attack successful. 
***if so, run player's version & calc damage & apply return of attack to enemy ptr

Eventually add:
Enemy Drops & Inventory (shared ptrs?)
Save player stats to a file?

On start:
Battle runs intro, (creates enemy ptr/ref) displays stats & options

*/