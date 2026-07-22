#include "Archer.h"
#include <iostream>

using namespace std;

Archer::Archer(string name, int stat[]) : player(name, stat, 4) {
    this->defence = this->defence + 30;
}

void Archer::attack(monster* Monster) {
    int BeforeHP = Monster->getHP();
    cout << "[Archer] Shoot the Bow! -> " << getPower() / 3 - Monster->getDefence() << " ( X3 ) Damage to " << Monster->getMname() << "!\n";

    if (getPower() / 3 - Monster->getDefence() <= 0)
    {
        for (int i = 0; i < 3; i++) {
            Monster->setHp(Monster->getHP() - 1);
        }
    }
    else
    {
        for (int i = 0; i < 3; i++) {
            Monster->setHp(Monster->getHP() - getPower() / 3 + Monster->getDefence());
        }
    }
    cout << Monster->getMname() << "'s HP : " << BeforeHP << " -> " << Monster->getHP() << endl;;

}

void Archer::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name : " << name << " | " << "Job : Archer | " << "Lv." << level << "\n";
    cout << "HP : " << hp << " | MP : " << mp << " | Attack : " << power << " | Defense : " << defence << "\n";
    cout << "------------------------------------\n";
}