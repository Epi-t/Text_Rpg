#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(string name, int stat[]) : player(name, stat, 1) {
    this->hp = this->hp + 30;
}

void Warrior::attack(monster* Monster) {
    int BeforeHP = Monster->getHP();
    cout << "[Warrior] Swing the sword! -> " << getPower() - Monster->getDefence() << " Damage to " << Monster->getMname() << "!\n";

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

void Warrior::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name : " << name << " | " << "Job : Warrior | " << "Lv." << level << "\n";
    cout << "HP : " << hp << " | MP : " << mp << " | Attack : " << power << " | Defense : " << defence << "\n";
    cout << "------------------------------------\n";
}