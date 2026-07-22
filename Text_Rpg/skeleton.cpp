#include "skeleton.h"
#include "player.h"
#include <iostream>

using namespace std;

skeleton::skeleton() : monster("Skeleton", 70, 35, 15, "Old Bone", 25, 35) {}

void skeleton::attack(player* Player) {
    if (Player == nullptr) return;
    int damage = power - Player->getDefence();
    if (damage <= 0) damage = 1;
    Player->takeDamage(damage);
    cout << name << " swings a rusty sword at you!" << endl;
    cout << "Remaining HP : " << Player->getHP() << endl;
}