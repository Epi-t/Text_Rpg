#include "Archer.h"
#include <iostream>

using namespace std;

Archer::Archer(string name, int stat[]) : player(name, stat, 4) {
    this->defence = this->defence + 30;
}

void Archer::attack() {
    cout << "* Shoot the bow!\n";
}

void Archer::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name : " << name << " | " << "Job : Archer | " << "Lv." << level << "\n";
    cout << "HP : " << hp << " | MP : " << mp << " | Attack : " << power << " | Defense : " << defence << "\n";
    cout << "------------------------------------\n";
}