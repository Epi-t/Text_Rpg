#include "Magician.h"
#include <iostream>

using namespace std;

Magician::Magician(string name, int stat[]) : player(name, stat, 2) {
    this->mp = this->mp + 30;
}

void Magician::attack() {
    cout << "* Fires a fireball!\n";
}

void Magician::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name : " << name << " | " << "Job : Magecian | " << "Lv." << level << "\n";
    cout << "HP : " << hp << " | MP : " << mp << " | Attack : " << power << " | Defense : " << defence << "\n";
    cout << "------------------------------------\n";
}