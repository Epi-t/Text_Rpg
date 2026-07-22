#include "Magician.h"
#include <iostream>

using namespace std;

Magician::Magician(string name, int stat[]) : player(name, stat, 2) {
    this->mp = this->mp + 30;
}


void Magician::attack(monster* Monster) {
    int BeforeHP = Monster->getHP();
    cout << "[Magician] Fires a fireball! -> " << getPower() - Monster->getDefence() << " Damage to " << Monster->getMname() << "!\n";

    if (getPower() - Monster->getDefence() <= 0)
    {
        Monster->setHp(Monster->getHP() - 1);
    }
    else
    {
        Monster->setHp(Monster->getHP() - getPower() + Monster->getDefence());
    }
    cout << Monster->getMname() << "'s HP : " << BeforeHP << " -> " << Monster->getHP() << endl;

}

void Magician::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name : " << name << " | " << "Job : Magecian | " << "Lv." << level << "\n";
    cout << "HP : " << hp << " | MP : " << mp << " | Attack : " << power << " | Defense : " << defence << "\n";
    cout << "------------------------------------\n";
}