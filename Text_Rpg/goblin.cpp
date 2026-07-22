#include "goblin.h"
#include "player.h"
#include <iostream>

using namespace std;

goblin::goblin() : monster("Goblin", 50, 25, 10, "Goblin Dagger", 30, 25) {}

void goblin::attack(player* Player) {
    if (Player == nullptr) return;
    int damage = power - Player->getDefence();
    if (damage <= 0) damage = 1;
    Player->takeDamage(damage);
    cout << name << " maliciously stabs you with a dagger!" << endl;
    cout << "Remaining HP : " << Player->getHP() << endl;
}