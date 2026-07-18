#include "Thief.h"
#include <iostream>

using namespace std;

Thief::Thief(string name, int stat[]) : player(name, stat, 3) {
    this->power = this->power + 30;
}

void Thief::attack() {
    cout << "* Stab with a dagger!\n";
}

void Thief::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name : " << name << " | " << "Job : Thief | " << "Lv." << level << "\n";
    cout << "HP : " << hp << " | MP : " << mp << " | Attack : " << power << " | Defense : " << defence << "\n";
    cout << "------------------------------------\n";
}