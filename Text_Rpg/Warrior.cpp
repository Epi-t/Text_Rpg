#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(string name, int stat[]) : player(name, stat, 1) {
    this->hp = this->hp + 30;
}

void Warrior::attack() {
    cout << "* Swing the sword!\n";
}

void Warrior::printPlayerStatus() {
    cout << "===========================\n";
    cout << name << "'s " << "Stats\n";
    cout << "===========================\n";
    cout << "HP : " << hp << " MP : " << mp << "\n";
    cout << "Attack : " << power << " defense : " << defence << "\n";
    cout << "===========================\n";
}