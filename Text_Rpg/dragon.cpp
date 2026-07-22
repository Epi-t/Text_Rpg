#include "dragon.h"
#include "player.h"
#include <iostream>

using namespace std;

dragon::dragon() : monster("Dragon", 500, 100, 50, "Dragon Scale", 500, 300) {}

void dragon::attack(player* Player) {
    if (Player == nullptr) return;
    int damage = power - Player->getDefence();
    if (damage <= 0) damage = 1;
    Player->takeDamage(damage);
    cout << name << " breathes scorching fire upon you!!!" << endl;
    cout << "Remaining HP : " << Player->getHP() << endl;
}