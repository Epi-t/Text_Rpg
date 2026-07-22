#include "orc.h"
#include "player.h"
#include <iostream>

using namespace std;

orc::orc() : monster("Orc", 120, 50, 20, "Heavy Axe", 60, 60) {}

void orc::attack(player* Player) {
    if (Player == nullptr) return;
    int damage = power - Player->getDefence();
    if (damage <= 0) damage = 1;
    Player->takeDamage(damage);
    cout << name << " smashes you with immense force!" << endl;
    cout << "Remaining HP : " << Player->getHP() << endl;
}